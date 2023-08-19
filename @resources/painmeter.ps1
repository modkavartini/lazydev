$skinsPath=$RmAPI.VariableStr("skinsPath")
$settingsIniPath=$RmAPI.VariableStr("settingsPath") + "Rainmeter.ini"
$excluded=$RmAPI.VariableStr("excluded") -replace '^$','thiswillnevermatchanythingoktrustmebro'
$seperator=$RmAPI.VariableStr("CRLF")
$showConfigs=$RmAPI.Variable("showConfigs")
$ded=$RmAPI.VariableStr("ded")
$prev="ehehehehehehehehe.ini"

function getConfig {
    param([string] $file)
    if($file -notmatch ".ini$|.inc$|.ps1$|.lua$") { break }
    if($file -match $prev) { break }
    $skinsPathR=[regex]::escape($skinsPath)
    $script:added=0
    $script:editing=$null
    $script:action=$null
    get-ChildItem $skinsPath $file -r | where-Object { ($_.Name -ceq $file) -and ($_.FullName -notmatch "@Backup") } | forEach-Object {
        $config=$_.fullname -replace "$skinsPathR|\\$file",''
        $root=$config -replace '\\.*',''
        if($config -match $excluded) { break }
        if($file -match ".ini$") { checkIni("$config") }
        if($file -match ".inc$|.ps1$|.lua$") { checkInc("$root") }
    }
    $script:prev=$file
}

function setConfig {
    $RmAPI.Bang("!setvariable action `"`"`"$action`"`"`"")
    $RmAPI.Bang("!setvariable editing `"$editing`"")
    $RmAPI.Bang("!setvariable highlight `"green`"")
}

function dedConfig {
    $RmAPI.Bang("!setvariable action `"[]`"")
    $RmAPI.Bang("!setvariable editing `"$ded`"")
    $RmAPI.Bang("!setvariable highlight `"red`"")
}

function checkIni {
    param([string] $config)
    $checkR=[regex]::escape($config)
    get-Content $settingsIniPath | select-String "\[$checkR\]" -context 1 | forEach-Object {
        $result=$_.Context.PostContext -replace '[^\d]',''
        if($result -gt 0) {
            $script:action+="[!refresh `"$config`"]"
            $script:editing+="$config" + "$seperator"
            $script:added++
        }
    }
    setConfig
    if($added -eq 0) { dedConfig }
}

function checkInc {
    param([string] $config)
    $checkR=[regex]::escape($config)
    get-Content $settingsIniPath | select-String "\[$checkR.*\]" -context 1 | forEach-Object {
        $found=$_.Line -replace '\[|\]',''
        $result=$_.Context.PostContext -replace '[^\d]',''
        if($result -gt 0) {
            if($found -match $excluded) { $script:action+="[]" }
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
}