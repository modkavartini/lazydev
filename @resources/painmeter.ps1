$skinsPath = $RmAPI.VariableStr("skinsPath")
$settingsIniPath = $RmAPI.VariableStr("settingsPath") + "Rainmeter.ini"
$rootConfig = $RmAPI.VariableStr("rootConfig")
$exclude = $RmAPI.VariableStr("exclude") -replace '^$','thiswillnevermatchanythingoktrustmebro'
$separator = if ($RmAPI.Variable("compactMode") -eq 1) { " & " } else { $RmAPI.VariableStr("configSeparator") }
$showConfigs = $RmAPI.Variable("showConfigs")
$dedAction = $RmAPI.VariableStr("defaultAction")
$dedEditor = $RmAPI.VariableStr("dedEditor")
$excText = $RmAPI.VariableStr("excludedText")
$excAction = $RmAPI.VariableStr("excludedAction")
$excludeInis = $RmAPI.Variable("excludeInis")

function getConfig {
    param([string] $file)
    if ($file -notmatch ".ini$|.inc$|.ps1$|.lua$") { break }
    $skinsPathR = [regex]::escape($skinsPath)
    $added = 0
    $excluded = 0
    get-ChildItem $skinsPath $file -r | where-Object { ($_.name -ceq $file) -and ($_.fullName -notmatch "@Backup|JaxCore") } | forEach-Object {
        if ($file -match "Rainmeter.ini") { setVars -a '!refreshApp' -e 'rainmeter settings' -h blue -b }
        $config = $_.fullName -replace "$skinsPathR|\\$file",''
        $root = $config -replace '\\.*',''
        if (($file -match "lazyVars.inc") -and ($root -match $rootConfig)) { setVars -a '!refresh' -e 'lazydev variables' -h blue -b }
        if ($file -match ".ini$") {
            $checkR = [regex]::escape($config)
            get-Content $settingsIniPath | select-String "\[$checkR\]" -context 1 | forEach-Object {
                $result = $_.context.postContext -replace '[^\d]',''
                if ($result -gt 0) {
                    if (($config -match $exclude) -and ($excludeInis -eq 1)) { 
                        $action += "[]" 
                        $excluded++
                    }
                    else {
                        $action += "[!refresh `"$config`"]"
                        $editing += "$config" + "$separator"
                    }
                    $added++
                }
            }
            if ($added -ne 0) { setVars -a $action -e $editing -h green }
            if ($added -eq 0) { setVars -a $dedAction -e $dedEditor -h red }
            if (($added -ne 0) -and ($excluded -eq $added) -and ($excludeInis -eq 1)) { setVars -a $excAction -e $excText -h red }
        }
        if ($file -match ".inc$|.ps1$|.lua$") {
            $checkR = [regex]::escape($root)
            get-Content $settingsIniPath | select-String "\[$checkR.*\]" -context 1 | forEach-Object {
                $found = $_.line -replace '\[|\]',''
                $result = $_.context.postContext -replace '[^\d]',''
                if ($result -gt 0) {
                    if ($found -match $exclude) { 
                        $action += "[]" 
                        $excluded++
                    }
                    else { 
                        $action += "[!refresh `"$found`"]"
                        if ($showConfigs -eq 1) { $editing += "$found" + "$separator" }
                        else { $editing += "$config" + "$separator" }
                    }
                    $added++
                }
            }
            if ($added -ne 0) { setVars -a $action -e $editing -h green }
            if ($added -eq 0) { setVars -a $dedAction -e $dedEditor -h red }
            if (($added -ne 0) -and ($excluded -eq $added)) { setVars -a $excAction -e $excText -h red }
        }
    }
}

$separatorR = [regex]::escape($separator)

function setVars {
    param(
        [string]
        $a,
        [string]
        $e,
        [string]
        $h,
        [switch]
        $b
    )
    $e = $e -replace "$separatorR$",""
    $RmAPI.Bang("!setVariable action `"`"`"$a`"`"`"")
    $RmAPI.Bang("!setVariable editing `"`"`"$e`"`"`"")
    $RmAPI.Bang("!setVariable highlight `"`"`"$h`"`"`"")
    if ($b) { break }
}

function minimizeAll {
    $shell = new-Object -ComObject Shell.Application
    $shell.minimizeAll()
}
