function update {
    stop-Process -name "Rainmeter"
    $API=invoke-WebRequest -uri "https://api.github.com/repos/modkavartini/lazydev/releases/latest" -useBasicParsing
    $URL=($API | convertFrom-Json).assets.browser_download_url
    $lV=($API | convertFrom-Json).tag_name
    $outPath="C:/Windows/Temp/lazy_zzz.rmskin"
    write-Host "> downloading lazydev $lV..." -foregroundColor red
    $WC=new-Object System.Net.WebClient
    $WC.downloadFile($URL, $outPath)
    write-Host "> installing lazydev $lV..." -foregroundColor green
    start-Sleep 1
    start-Process $outPath
    if($null -notmatch (get-Process "SkinInstaller" -ea 0)) {
        start-Sleep 2
        $wShell=new-Object -ComObject WScript.Shell
        $wShell.sendKeys('~')
    }
}

update