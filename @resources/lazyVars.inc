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

scheme=2
;0-3 are catppuccin colors.
;4 and any more you add will be custom.
;you may add custom colors starting with the index 4 and so on.

bg=[#bg[#scheme]]
text=[#main[#scheme]]
green=[#green[#scheme]]
red=[#red[#scheme]]
blue=[#blue[#scheme]]

fontFace=JetBrains Mono
textSize=13
maxWidth=350
padding=17
cornerRoundness=15

defaultAction=[]
;the action to execute if ctrl+s is pressed without any detected skins.
;[!refreshApp] can be used to refresh all active skins in this scenario.

checkForUpdates=1
;0 or 1
;notifies you of any available updates to the skin.

compactMode=1
;if = 1, shows ONLY the config names and puts everything on a single line. #maxWidth# is still applicable.
;if = 0, shows `#editorText#` or `#focusText#` above the config(s).
;also when = 1, `#editorText#`, `#focusText#`, `#textSeparator#` and `#configSeparator#` are obsolete.

compactSeparator=" & "

compactSepColor=[#blue]
;the color of the `#compactSeparator#` when `#compactMode#` = 1

textSeparator=#CRLF#
;the separator between `#editorText#` or `#focusText#` text and the detected config(s).
;#CRLF# (nextLine) by default.

; ███████ ██████  ██ ████████  ██████  ██████  
; ██      ██   ██ ██    ██    ██    ██ ██   ██ 
; █████   ██   ██ ██    ██    ██    ██ ██████  
; ██      ██   ██ ██    ██    ██    ██ ██   ██ 
; ███████ ██████  ██    ██     ██████  ██   ██ 

editorText=editing:
dedEditor=ded skin xd
excludedText=excluded file!

configSeparator=#CRLF#
;the separator between multiple configs if any.
;#CRLF# by default.

;initial values

editing=edit a skin!
action=[]
highlight=red

hidden=1
;if = 1, the skin is invisible on load/refresh and shows itself only after config detection.
;if = 0, the skin is always visible.

exclude=catppuccin\\bar\\assist\\bg$
;configs set in the above variable will be ignored by the skin.
;it is used as a regexp match. hence, regexps are allowed.
;this also means that you have to escape your backslashes :)
;lazydev itself is excluded by default.

excludeInis=1
;if = 1, excludes .ini files if they are from the configs specified in the above variable.
;if = 0, does not exclude .ini files but only @inc files.

excludedAction=#defaultAction#
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
