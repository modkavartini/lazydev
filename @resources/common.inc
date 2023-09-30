[rainmeter]
update=100
defaultWindowX=50%
defaultWindowY=50%
dynamicWindowSize=1
onRefreshAction=[!writeKeyValue metadata version "#version#"][!writeKeyValue MonD Version "#version#" "#@#mond.inc"][!delay 10000][!setOption display meterStyle "text|[*#configSet*]"]
contextTitle2=edit variables
contextAction2=["#@#lazyVars.inc"]

[variables]
configSet=0

[setAnchorX]
measure=calc
formula=(#currentConfigX#>=#screenAreaWidth#/2)?100:0
onChangeAction=[!setWindowPosition #currentConfigX# #currentConfigY# [setAnchorX:]% [setAnchorY:]%]
dynamicVariables=1

[setAnchorY]
measure=calc
formula=(#currentConfigY#>=#screenAreaWidth#/2)?100:0
onChangeAction=[!setWindowPosition #currentConfigX# #currentConfigY# [setAnchorX:]% [setAnchorY:]%]
dynamicVariables=1

[current]
measure=string
string=[#currentFile]
substitute=".ini":""
disabled=1

[text]
container=bg
fontColor=[#text]
fontFace=#fontFace#
fontSize=#textSize#
inlineSetting=color|[#[#highlight]]
inlineSetting2=color|[#compactSepColor]
inlinePattern2=[#compactSeparator]
stringAlign=leftTop
solidColor=[#bg]
padding=[#padding],[#padding],[#padding],[#padding]
clipString=2
clipStringW=([#maxWidth]-[#padding]*2)
antiAlias=1
dynamicVariables=1
hidden=[#hidden]

[0]
inlinePattern=(.*)
text=[#editing]

[1]
inlinePattern=#textSeparator#(.*)
text=[#[&current]Text]#textSeparator#[#editing]

[display]
meter=string
meterStyle=text|[#configSet]

[bg]
meter=shape
shape=rectangle 0,0,[display:W],[display:H],#cornerRoundness# | strokeWidth 0 
dynamicVariables=1
hidden=[#hidden]
