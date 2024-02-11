Set WshShell = WScript.CreateObject("Wscript.Shell")
WScript.Sleep 1000
for i = 1 to 200
WshShell.Sendkeys "^v"
WshShell.Sendkeys i
WshShell.Sendkeys "%s"
Next