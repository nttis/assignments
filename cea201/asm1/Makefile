main.obj: main.asm
	wine ml.exe /nologo /c /coff /Zi main.asm

main.exe: main.obj
	wine link.exe /nologo /subsystem:console /entry:start kernel32.lib user32.lib main.obj

run: main.exe
	wine main.exe

clean:
	rm main.obj main.exe
