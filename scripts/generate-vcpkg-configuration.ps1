# Generate vcpkg-configuration.json with a baseline pointing to the current vcpkg HEAD
# Run this from the repository root (where vcpkg.json lives) in PowerShell:
#   .\scripts\generate-vcpkg-configuration.ps1

# Fetch the latest vcpkg commit hash and write vcpkg-configuration.json
$baseline = (git ls-remote https://github.com/microsoft/vcpkg HEAD).Split()[0]
@"
{
  "default-registry": {
    "kind": "git",
    "repository": "https://github.com/microsoft/vcpkg",
    "baseline": "$baseline"
  }
}
"@ | Out-File -Encoding utf8 vcpkg-configuration.json

Write-Host "Wrote vcpkg-configuration.json with baseline $baseline"
