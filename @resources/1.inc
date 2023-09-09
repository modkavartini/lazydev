[variables]
version=1.2.2

[latest]
measure=webparser
url=https://api.github.com/repos/modkavartini/lazydev/releases/latest
regexp=(?siU).*"name":"v(.*)"
stringindex=1
substitute="":"[#version]"

[cVerNum]
measure=string
string=[#version]
substitute=".":""

[lVerNum]
measure=string
string=[&latest]
substitute=".":""
dynamicvariables=1

[hasUp]
measure=calc
formula=[&lVerNum]>[&cVerNum]?1:0
ifEqualValue=1
ifEqualAction=[!setOption display meterStyle text|upAvailable][!updateMeter text][!redraw]
dynamicVariables=1

[upAvailable]
text=an update is available.#textSeparator#click here to install!
fontColor=[#green]
inlineSetting=color|[#red]
inlinePattern=#textSeparator#(.*)
leftMouseUpAction=[!commandMeasure psrm "minimizeAll"][powershell "#@#update.ps1"]
