[current]
measure=string
string=[#currentFile]
substitute=".ini":""

[text]
container=bg
W=([#W]-[#padding]*2)
fontColor=[#text]
fontFace=JetBrains Mono
fontSize=13
inlineSetting=color|[#[#highlight]]
inlinePattern=#CRLF#(.*)
stringAlign=leftTop
text=[#[&current]Text]#CRLF#[#editing]
solidColor=[#bg]
padding=[#padding],[#padding],[#padding],[#padding]
clipString=2
antiAlias=1
dynamicVariables=1

[display]
meter=string
meterStyle=text

[icon]
Meter=Shape
container=bg
Shape = Path Path1 | StrokeWidth 0 | FillColor [#text]
Shape2 = Path Path2 | StrokeWidth 0
Shape3 = Combine Shape1 | XOR Shape2 | scale 45,45
Path1 = 0.98004752, 0.26404903 | LineTo 0.87157872, 0.37379394 | LineTo 0.87157872, 0.11474492 | LineTo 0.38155496, 0.11474492 | LineTo 0.38155496, 0.38655497 | LineTo 0.1084688, 0.38655497 | LineTo 0.1084688, 0.98504753 | LineTo 0.87157872, 0.98504753 | LineTo 0.87157872, 0.83574342 | LineTo 0.98004752, 0.72599851 | LineTo 0.98004752, 1.03992 | CurveTo 0.96345818, 1.0794792, 0.98004752, 1.0628899 | CurveTo 0.92645118, 1.0947924, 0.94814494, 1.0947924 | LineTo 0.05359635, 1.0947924 | CurveTo 0.01531324, 1.0794792, 0.03190259, 1.0947924 | CurveTo 0, 1.03992, 0, 1.0628899 | CurveTo 0, 1.03992, 0, 1.03992 | CurveTo 0, 1.03992, 0, 1.03992 | LineTo 0, 1.03992 | LineTo 0, 0.33168252 | LineTo 0.32668251, 0.00500001 | LineTo 0.92517507, 0.00500001 | CurveTo 0.96345818, 0.02158936, 0.94814494, 0.00500001 | CurveTo 0.98004752, 0.05987246, 0.98004752, 0.0369026 | LineTo 0.98004752, 0.26404903 | ClosePath 1
Path2 = 1.0221589, 0.37634614 | LineTo 1.1000013, 0.45291236 | LineTo 0.67633488, 0.87657873 | LineTo 0.59849256, 0.87657873 | LineTo 0.59849256, 0.80001252 | LineTo 1.0221589, 0.37634614 | ClosePath 1
X=([#W]-25-[#padding]-1)
Y=(([display:H]/2)-1)
dynamicVariables=1
hidden=(1-[#showIcon])

[bg]
meter=shape
shape=rectangle 0,0,[display:W],[display:H],#cornerRoundness# | strokeWidth 0 
dynamicVariables=1
