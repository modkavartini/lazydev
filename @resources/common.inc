[rainmeter]
update=100
defaultWindowX=50%
defaultWindowY=50%
onRefreshAction=[!writeKeyValue metadata version "#version#"][!writeKeyValue MonD Version "#version#" "#@#mond.inc"][!delay 10000][!setOption display meterStyle text]
contextTitle2=edit variables
contextAction2=["#@#lazyVars.inc"]