Set WshShell = WScript.CreateObject("Wscript.Shell")
WScript.Sleep 2000
for i = 1 to 100
WshShell.Sendkeys "^v"
WshShell.Sendkeys i
WshShell.Sendkeys "%s"
Next