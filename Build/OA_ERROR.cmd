set /a FailCounter+=1

COLOR 47

echo.
echo ***************************
echo ********** ERROR **********
echo ***************************
echo.

if not [!LogFile!] == [] (
  echo.>> !LogFile!
  echo ***************************>> !LogFile!
  echo ********** ERROR **********>> !LogFile!
  echo ***************************>> !LogFile!
  echo.>> !LogFile!
)

if not [%1] == [NOPAUSE] pause
