cls
rmdir build /s /q
arduino-cli compile --fqbn arduino:avr:leonardo hotkeys

arduino-cli upload -p COM9 --fqbn arduino:avr:leonardo hotkeys