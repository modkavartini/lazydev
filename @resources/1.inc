[variables]
version=1.0
gh=modkavartini/lazydev

[MonDGud]
measure=string
string=#version#
onUpdateAction=[!writekeyvalue MonD Version "#version#" "#@#mond.inc"][!disablemeasure [#currentSection]]
updateDivider=-1

[latest]
measure=webparser
url=https://api.github.com/repos/[#gh]/releases/latest
regexp=(?siU).*"name":"v(.*)".*"browser_download_url":"(.*)"
stringindex=1
substitute="":"[#version]"

[download]
measure=webparser
url=[latest]
stringindex=2

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
ifEqualAction=[!setOption text meterStyle style|upAvailable][!updateMeter text][!redraw]
dynamicVariables=1

[upAvailable]
text=an update is available.#CRLF#click here to download!
fontColor=[#green]
inlineSetting=color|[#red]
leftMouseUpAction=[&download]