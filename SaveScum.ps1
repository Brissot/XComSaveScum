#Replace "save129" with what your ironman save is :)

$save="save129"

############################

Set-PSDebug -Off
$game_path="$env:USERPROFILE\Documents\my games\XCOM - Enemy Within\XComGame\"

#make SaveScum folder
if (-Not (Test-Path -Path $game_path\SaveScum)) {
    New-Item "$game_path\SaveScum" -itemType Directory
}

#set up names
$source= "$game_path\SaveData\$save"
$date= Get-Date -Format "yyyy-MM-dd HH-mm-ss"
$destination= "$game_path\SaveScum\$date"

Copy-Item $source $destination