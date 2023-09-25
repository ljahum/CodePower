# C:\Users\test_user\Documents\PowerShell\Microsoft.PowerShell_profile.ps1
echo "hello world"
echo $PROFILE
# oh-my-posh init pwsh | Invoke-Expression

$Env:http_proxy="http://127.0.0.1:7890";$Env:https_proxy="http://127.0.0.1:7890"


oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH/powerlevel10k_lean.omp.json" | Invoke-Expression


Import-Module posh-git


# Import-Module oh-my-posh


Import-Module PSReadLine
Set-PSReadLineOption -PredictionSource History
Set-PSReadLineOption -HistorySearchCursorMovesToEnd
Set-PSReadLineKeyHandler -Key "Tab" -Function MenuComplete


Set-PSReadLineOption -PredictionViewStyle ListView




# Function Edit-Profile
# {
#     vim $profile
# }