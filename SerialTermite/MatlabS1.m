%Mi primer programa de comunicación serial

%Crear un objeto, con las caracteristicas de la comunicación.

%pause(1)
ObjetoSerial = instrfind('Type', 'serial', 'Port', 'COM26', 'Tag', '');
%pause(1)
if isempty(ObjetoSerial)
    ObjetoSerial = serial('COM26');
else
    fclose(ObjetoSerial);
    ObjetoSerial = ObjetoSerial(1)
end
%pause(1)
ObjetoSerial.BaudRate = 9600;
fopen(ObjetoSerial);
flushinput(ObjetoSerial)


pause(2)

%%%%%%%%%%%%%%Lectura de la primera variable%%%%%%%%%%%%%%%%
fwrite(ObjetoSerial, 'A','char');
pause(0.001)
datos_leido = fread(ObjetoSerial, 1, 'uint16')

pause(1)


%%%%%%%%%%%%%%Lectura de la segunda variable%%%%%%%%%%%%%%%%
fwrite(ObjetoSerial, 'B','char');
pause(0.001)

datos_leido2 = fread(ObjetoSerial, 1, 'float')


%%%%%%%%%%%%%%Lectura de la tercer variable%%%%%%%%%%%%%%%%
fwrite(ObjetoSerial, 'C','char');
pause(0.001)

datos_leido3 = fread(ObjetoSerial, 1, 'int16')


%%%%%%%%%%%%%%Lectura de la cuarta variable%%%%%%%%%%%%%%%%
fwrite(ObjetoSerial, 'D','char');
pause(0.001)

datos_leido4 = char(fread(ObjetoSerial, 1, 'char'))


%%%%%%%%%%%%%%Lectura de la quinta variable%%%%%%%%%%%%%%%%
fwrite(ObjetoSerial, 'F','char');
pause(0.001)

datos_leido5 = fscanf(ObjetoSerial,'%s',4)





flushinput(ObjetoSerial);
fclose(ObjetoSerial);
delete(ObjetoSerial);


