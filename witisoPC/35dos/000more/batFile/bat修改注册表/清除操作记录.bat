@echo off
echo windows registry editor version 5.00 >temp.reg
echo 正在清除"运行"对话框中的历史记录...
echo [-hkey_current_user\software\microsoft\windows\currentVersion\explorer\runMRU] >>temp.reg
echo 正在清除windows搜索历史记录...
echo [-hkey_current_user\software\microsoft\search assistant\acmru] >>temp.reg
echo 正在清除访问web站点的历史记录...
echo [-hkey_current_user\software\microsoft\internet explorer\typedURLs] >>temp.reg
echo 正在清除正在访问过的历史文件夹信息...
echo [-hkey_current_user\software\microsoft\windows\currentVersion\explorer\recent docs\folder] >>temp.reg
echo 正在清除"我的最近文档"中记录的访问文件记录...
echo [-hkey_current_user\software\microsoft\windows\currentVersion\explorer\comdlg32\opensavemru] >>temp.reg
regedit /s temp.reg
del /q /f temp.reg >nul
