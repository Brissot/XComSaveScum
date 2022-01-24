#Replace "save129" with what your ironman save is :)

$save="save129"

############################

Set-PSDebug -Off
$game_path="$env:USERPROFILE\Documents\my games\XCOM - Enemy Within\XComGame\"

#get most recent file
$datum= Get-ChildItem -Path "$game_path\SaveScum\" | Sort-Object LastAccessTime -Descending | Select-Object -First 1
$source= "$game_path\SaveScum\$datum"
$destination= "$game_path\SaveData\$save"

Copy-Item $source $destination