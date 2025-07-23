param (
    [string]$Message = "Auto commit"
)

if ($Message -eq "") {
    $Message = "Auto commit"
}

cd..
cd..
.\gitpush.ps1 "$Message"
# This script changes the directory to the parent directory twice and then calls another PowerShell script to push changes to a Git repository.