@cd C:\Users\mrjac\OneDrive\Documents\Visual Studio 2022\Templates\ItemTemplates\Otter Class\

@for /f "delims=" %%y IN ('FINDSTR "@since" OtterBase.h') DO SET line=%%y
@SET since=%line:~18%
@SET line=%line:~0,18%
@SET /A since=%since%+1

@FoR /f "delims=" %%z IN (OtterBase.h) DO IF "%%z"=="#pragma once" (>OtterBase.h ECHO(%%z) ELSE (echo %%z |FINDSTR "@since" >nul && (>>OtterBase.h ECHO(%line%%since%) || (>>OtterBase.h ECHO(%%z))

@cd ..\Otter Header File
@FOR /f "delims=" %%z IN (OtterBase.h) DO IF "%%z"=="#pragma once" (>OtterBase.h ECHO(%%z) ELSE (echo %%z |FINDSTR "@since" >nul && (>>OtterBase.h ECHO(%line%%since%) || (>>OtterBase.h ECHO(%%z))