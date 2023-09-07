[variables]

;if editor.ini is loaded, the skin will automatically refresh upon ctrl+S :)

;  ██████  ██████  ███    ███ ███    ███  ██████  ███    ██ 
; ██      ██    ██ ████  ████ ████  ████ ██    ██ ████   ██ 
; ██      ██    ██ ██ ████ ██ ██ ████ ██ ██    ██ ██ ██  ██ 
; ██      ██    ██ ██  ██  ██ ██  ██  ██ ██    ██ ██  ██ ██ 
;  ██████  ██████  ██      ██ ██      ██  ██████  ██   ████ 

@include=#@#catbussin.inc

;custom colors.

bg4=0,0,0
main4=255,255,255
green4=0,255,0
red4=255,0,0
blue4=0,0,255

scheme=3
;0-3 are catppuccin colors.
;4 and any more you add will be custom.
;you may add custom colors starting with the index 4 and so on.

bg=[#bg[#scheme]]
text=[#main[#scheme]]
green=[#green[#scheme]]
red=[#red[#scheme]]
blue=[#blue[#scheme]]

textSize=13
maxWidth=350
padding=21
cornerRoundness=15

defaultAction=[]
;the action to execute if ctrl+s is pressed without any detected skins.
;[!refreshApp] can be used to refresh all active skins in this scenario.

checkForUpdates=1
;0 or 1
;notifies you of any available updates to the skin.

; ███████ ██████  ██ ████████  ██████  ██████  
; ██      ██   ██ ██    ██    ██    ██ ██   ██ 
; █████   ██   ██ ██    ██    ██    ██ ██████  
; ██      ██   ██ ██    ██    ██    ██ ██   ██ 
; ███████ ██████  ██    ██     ██████  ██   ██ 

editorText=editing:
dedEditor=ded skin xd
excludedText=excluded file!

;initial values
editing=edit a skin!
action=[]
highlight=red

exclude=.lazydev|catppuccin\\bar\\assist\\bg$
;configs set in the above variable will be ignored by the skin.
;it is used as a regexp match. hence, regexps are allowed.
;this also means that you have to escape your backslashes :)

excludeInis=1
;if = 1, excludes .ini files if they are from the configs specified in the above variable.
;if = 0, does not exclude .ini files but only @inc files.

excludedAction=[]
;the action to execute if ctrl+s is pressed when an excluded config is detected.

codeEditors=Code.exe
;regexp match for the code editor(s) used.
;notepad and notepad++ are already included but any others need to be in this variable.

showConfigs=1
;if = 1, displays the active configs from the rootconfig of the @inc file.
;if = 0, displays the rootconfig name instead.

; ███████  ██████   ██████ ██    ██ ███████ 
; ██      ██    ██ ██      ██    ██ ██      
; █████   ██    ██ ██      ██    ██ ███████ 
; ██      ██    ██ ██      ██    ██      ██ 
; ██       ██████   ██████  ██████  ███████ 

focusText=focusing:
dedFocus=ctrl + click a skin!