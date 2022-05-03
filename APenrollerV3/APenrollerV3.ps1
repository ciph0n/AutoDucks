$env:Path += ";C:\Program Files\WindowsPowerShell\Scripts"
Set-ExecutionPolicy -Scope Process -ExecutionPolicy RemoteSigned
Install-Script -Name Get-WindowsAutoPilotInfo
Get-WindowsAutoPilotInfo -online
Set-ExecutionPolicy -bypass
Install-Script -Name Get-AutopilotDiagnostics