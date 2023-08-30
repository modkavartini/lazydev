$skinsPath=$RmAPI.VariableStr("skinsPath")
$settingsIniPath=$RmAPI.VariableStr("settingsPath") + "Rainmeter.ini"
$rootConfig=$RmAPI.VariableStr("rootConfig")
$exclude=$RmAPI.VariableStr("exclude") -replace '^$','thiswillnevermatchanythingoktrustmebro'
$seperator=$RmAPI.VariableStr("CRLF")
$showConfigs=$RmAPI.Variable("showConfigs")
$defaultAction=$RmAPI.VariableStr("defaultAction")
$dedEditor=$RmAPI.VariableStr("dedEditor")
$excludedText=$RmAPI.VariableStr("excludedText")
$excludedAction=$RmAPI.VariableStr("excludedAction")
$excludeInis=$RmAPI.Variable("excludeInis")

function getConfig {
    param([string] $file)
    if($file -notmatch ".ini$|.inc$|.ps1$|.lua$") { break }
    $skinsPathR=[regex]::escape($skinsPath)
    $script:added=0
    $script:excluded=0
    $script:editing=$null
    $script:action=$null
    get-ChildItem $skinsPath $file -r | where-Object { ($_.Name -ceq $file) -and ($_.FullName -notmatch "@Backup") } | forEach-Object {
        $config=$_.fullname -replace "$skinsPathR|\\$file",''
        $root=$config -replace '\\.*',''
        if(($file -match "lazyVars.inc") -and ($root -match $rootConfig)) { editingVars }
        if($file -match ".ini$") { checkIni("$config") }
        if($file -match ".inc$|.ps1$|.lua$") { checkInc("$root") }
    }
}

function setConfig {
    $RmAPI.Bang("!setVariable action `"`"`"$action`"`"`"")
    $RmAPI.Bang("!setVariable editing `"$editing`"")
    $RmAPI.Bang("!setVariable highlight `"green`"")
}

function dedConfig {
    $RmAPI.Bang("!setVariable action `"`"`"$defaultAction`"`"`"")
    $RmAPI.Bang("!setVariable editing `"$dedEditor`"")
    $RmAPI.Bang("!setVariable highlight `"red`"")
}

function excConfig {
    $RmAPI.Bang("!setVariable action `"`"`"$excludedAction`"`"`"")
    $RmAPI.Bang("!setVariable editing `"$excludedText`"")
    $RmAPI.Bang("!setVariable highlight `"red`"")
}

function editingVars {
    $RmAPI.Bang("!setVariable action `"[!refresh]`"")
    $RmAPI.Bang("!setVariable editing `"lazydev variables`"")
    $RmAPI.Bang("!setVariable highlight `"blue`"")
    break
}

function checkIni {
    param([string] $config)
    $checkR=[regex]::escape($config)
    get-Content $settingsIniPath | select-String "\[$checkR\]" -context 1 | forEach-Object {
        $result=$_.Context.PostContext -replace '[^\d]',''
        if($result -gt 0) {
            if(($config -match $exclude) -and ($excludeInis -eq 1)) { 
                $script:action+="[]" 
                $script:excluded++
            }
            else {
                $script:action+="[!refresh `"$config`"]"
                $script:editing+="$config" + "$seperator"
            }
            $script:added++
        }
    }
    setConfig
    if($added -eq 0) { dedConfig }
    if(($added -ne 0) -and ($excluded -eq $added) -and ($excludeInis -eq 1)) { excConfig }
}

function checkInc {
    param([string] $config)
    $checkR=[regex]::escape($config)
    get-Content $settingsIniPath | select-String "\[$checkR.*\]" -context 1 | forEach-Object {
        $found=$_.Line -replace '\[|\]',''
        $result=$_.Context.PostContext -replace '[^\d]',''
        if($result -gt 0) {
            if($found -match $exclude) { 
                $script:action+="[]" 
                $script:excluded++
            }
            else { 
                $script:action+="[!refresh `"$found`"]"
                if($showConfigs -eq 1) { $script:editing+="$found" + "$seperator" }
                else { $script:editing+="$config" }
            }
            $script:added++
        }
    }
    setConfig
    if($added -eq 0) { dedConfig }
    if(($added -ne 0) -and ($excluded -eq $added)) { excConfig }
}

function minimizeAll {
    $shell=new-Object -ComObject Shell.Application
    $shell.minimizeAll()
}
