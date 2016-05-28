; example2.nsi
;
; This script is based on example1.nsi, but it remember the directory, 
; has uninstall support and (optionally) installs start menu shortcuts.
;
; It will install example2.nsi into a directory that the user selects,

;--------------------------------

; The name of the installer
Name "TicTacToe"

; The file to write
OutFile "TicTacToeInstaller.exe"

; The default installation directory
InstallDir $PROGRAMFILES\TicTacToe

; Registry key to check for directory (so if you install again, it will 
; overwrite the old one automatically)
InstallDirRegKey HKLM "Software\bogolyandras\TicTacToe" "Install_Dir"

; Request application privileges for Windows Vista
RequestExecutionLevel admin

;--------------------------------

; Pages

Page components
Page directory
Page instfiles

UninstPage uninstConfirm
UninstPage instfiles

;--------------------------------

; The stuff to install
Section "TicTacToe (required)"

  SectionIn RO
  
  ; Set output path to the installation directory.
  SetOutPath $INSTDIR
  
  ; Put file there
  File "TicTacToe.exe"
  File "Qt5Widgets.dll"
  File "Qt5Gui.dll"
  File "Qt5Core.dll"
  File "libwinpthread-1.dll"
  File "libstdc++-6.dll"
  File "libgcc_s_dw2-1.dll"

  SetOutPath "$INSTDIR\platforms"
  File "qwindows.dll"
  
  ; Write the installation path into the registry
  WriteRegStr HKLM SOFTWARE\bogolyandras\TicTacToe "Install_Dir" "$INSTDIR"
  
  ; Write the uninstall keys for Windows
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\bogolyandras\TicTacToe" "DisplayName" "NSIS Example2"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\bogolyandras\TicTacToe" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\bogolyandras\TicTacToe" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\bogolyandras\TicTacToe" "NoRepair" 1
  WriteUninstaller "uninstall.exe"
  
SectionEnd

; Optional section (can be disabled by the user)
Section "Start Menu Shortcuts"

  CreateDirectory "$SMPROGRAMS\TicTacToe"
  CreateShortCut "$SMPROGRAMS\TicTacToe\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  CreateShortCut "$SMPROGRAMS\TicTacToe\TicTacToe.lnk" "$INSTDIR\TicTacToe.exe" "" "$INSTDIR\TicTacToe.exe" 0
  
SectionEnd

;--------------------------------

; Uninstaller

Section "Uninstall"
  
  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\bogolyandras\TicTacToe"
  DeleteRegKey HKLM SOFTWARE\bogolyandras\TicTacToe

  ; Remove files and uninstaller
  Delete $INSTDIR\uninstall.exe
  Delete "$INSTDIR\*"
  Delete "$INSTDIR\platforms\*"
  RMDir  "$INSTDIR\platforms"
  RMDir  "$INSTDIR"

  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\TicTacToe\*.*"
  RMDir "$SMPROGRAMS\TicTacToe"

  ; Remove directories used
  RMDir "$SMPROGRAMS\TicTacToe"
  RMDir "$INSTDIR"

SectionEnd
