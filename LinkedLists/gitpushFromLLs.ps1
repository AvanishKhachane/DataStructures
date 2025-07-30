param 
(
    [string]$Message = "Auto commit"
)

if ($Message -eq "") {
    $Message = "Auto commit"
}

Set-Location ..

.\gitpush.ps1 "$Message"
# This script changes the directory to the parent directory twice and then calls another PowerShell script to push changes to a Git repository.

Set-Location (Split-Path -Leaf $PSScriptRoot)param 
(
    [string]$Message = "Auto commit"
)

if ($Message -eq "") {
    $Message = "Auto commit"
}

$foldername = Split-Path -Leaf $PSScriptRoot

Set-Location ..

.\gitpush.ps1 "$Message"
# This script changes the directory to the parent directory twice and then calls another PowerShell script to push changes to a Git repository.

Set-Location $foldername