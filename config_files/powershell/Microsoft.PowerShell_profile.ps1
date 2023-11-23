function Check-IsElevated
{
    $id = [System.Security.Principal.WindowsIdentity]::GetCurrent()
    $p = New-Object System.Security.Principal.WindowsPrincipal($id)
    if ($p.IsInRole([System.Security.Principal.WindowsBuiltInRole]::Administrator))
   { Write-Output $true }
    else
   { Write-Output $false }
}

# theme部分美容无法加载的情况,选择手动的主题启动方式
function op{
    # oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH/powerlevel10k_lean.omp.json" | Invoke-Expression
    oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH/peru.omp.json" | Invoke-Expression
    # peru
}


echo "hello world"
echo $PROFILE
# oh-my-posh init pwsh | Invoke-Expression

$Env:http_proxy="http://127.0.0.1:10809";$Env:https_proxy="http://127.0.0.1:10809"





Import-Module posh-git

# change to user theme or admin theme

if (-not(Check-IsElevated))
{
    echo "[#]"
    echo "[+] not Administrator"
    echo "[+] loading beauty?"
    
    # oh-my-posh init pwsh --config "$env:POSH_THEMES_PATH/1_shell.omp.json" | Invoke-Expression
    # 1_shell.omp.json
}
else{
    echo "[-] Administrator"
}

# Import-Module oh-my-posh


Import-Module PSReadLine
Set-PSReadLineOption -PredictionSource History
Set-PSReadLineOption -HistorySearchCursorMovesToEnd
Set-PSReadLineKeyHandler -Key "Tab" -Function MenuComplete


Set-PSReadLineOption -PredictionViewStyle ListView


Set-Alias ls lsd


