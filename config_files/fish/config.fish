# ~/.config/fish/config.fish
if status is-interactive
    # Commands to run in interactive sessions can go here
end


# sth error
# alias cls="clear"
alias ls="lsd"

function clash
    set IP "192.168.244.1"
    # set IP="192.168.244.1"

    export http_proxy="http://"+IP+":7890/"
    export https_proxy="http://"+IP+":7890/"
   echo "proxy on"
end⏎