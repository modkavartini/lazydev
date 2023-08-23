function update {
    $API=invoke-WebRequest -uri "https://api.github.com/repos/modkavartini/lazydev/releases/latest" -useBasicParsing
    $URL=($API | convertFrom-Json).assets.browser_download_url
    $lV=($API | convertFrom-Json).name
    $outPath="C:/Windows/Temp/lazy_zzz.rmskin"
    write-Host "> downloading lazydev $lV..." -foregroundColor red
    $WC=new-Object System.Net.WebClient
    $WC.downloadFile($URL, $outPath)
    write-Host "> installing lazydev $lV..." -foregroundColor green
    start-Sleep 1
    $shell=new-Object -ComObject Shell.Application
    $shell.minimizeAll()
    start-Process $outPath
    if($null -notmatch (get-Process "SkinInstaller" -ea 0)) {
        start-Sleep 2
        $wShell=new-Object -ComObject WScript.Shell
        $wShell.sendKeys('~')
    }
}

update