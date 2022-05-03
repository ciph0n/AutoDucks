$serial = Get-WmiObject Win32_bios | Select -expand serialnumber; Rename-Computer REDACTED-$serial;
$env:Path += ";C:\Program Files\WindowsPowerShell\Scripts"
Set-ExecutionPolicy -Scope Process -ExecutionPolicy RemoteSigned
Install-Script -Name Get-WindowsAutoPilotInfo
Get-WindowsAutoPilotInfo -online