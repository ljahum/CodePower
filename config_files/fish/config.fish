# ~/.config/fish/config.fish
if status is-interactive
    # Commands to run in interactive sessions can go here
end

alias cls="clear"
alias ls="lsd"

function clash
    export http_proxy="http://192.168.244.1:7890/"
    export https_proxy="http://192.168.244.1:7890/"
   echo "proxy on"
end