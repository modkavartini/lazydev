[variables]

;  ██████  ██████  ███    ███ ███    ███  ██████  ███    ██ 
; ██      ██    ██ ████  ████ ████  ████ ██    ██ ████   ██ 
; ██      ██    ██ ██ ████ ██ ██ ████ ██ ██    ██ ██ ██  ██ 
; ██      ██    ██ ██  ██  ██ ██  ██  ██ ██    ██ ██  ██ ██ 
;  ██████  ██████  ██      ██ ██      ██  ██████  ██   ████                                                                 
                                                                              
bg=17,17,27
text=205,214,244
green=166,227,161
red=243,139,168

W=350
padding=21
cornerRoundness=15

;initial values
editing=loading...
action=[]
highlight=text

showIcon=0
;show an icon to the right

defaultAction=[]
;the action to execute if ctrl+s is pressed without any detected skins
;[!refreshApp] can be used to refresh all active skins in this scenario

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

excluded=catppuccin\\bar\\bg$
;configs set in the above variable will be ignored by the skin.
;it is used as a regexp match. hence, regexps are allowed.
;this also means that you have to escape your backslashes :)

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
