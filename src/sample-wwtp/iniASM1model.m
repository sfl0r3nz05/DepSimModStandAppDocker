% Valores por defecto del Modelo ASM1
NUMESTADOSMODASM1 = 14;
NUMREACCIONESBIOL = 9;

EST_SS = 1;
EST_SO = 2;
EST_SI = 3;
EST_SNO = 4;
EST_SNH = 5;
EST_SND = 6;
EST_SALK = 7;

EST_XI = 8;
EST_XS = 9;
EST_XBH = 10;
EST_XBA = 11;
EST_XP = 12;
EST_XND = 13;
EST_XIN = 14;

CRECIM_AEROB_XBH = 1;
CRECIM_ANOX_XBH = 2;	
CRECIM_AEROB_XBA = 3;
LISIS_XBH = 4;
LISIS_XBA = 5;
AMONIFICACION = 6;
HIDROLISIS_XS = 7;
HIDROLISIS_XND = 8;
AERACION = 9;


% Coeficientes Estequiometricos
ParamsEsteq(1) = 0.67;      % Yh
ParamsEsteq(2) = 0.24;      % Ya
ParamsEsteq(3) = 0.08;      % fp 
ParamsEsteq(4) = 0.08;     % iXB
ParamsEsteq(5) = 0.06;      % iXP
ParamsEsteq(6) = 0.676;      % iVSS_XB
ParamsEsteq(7) = 0.676;      % iVSS_XI
ParamsEsteq(8) = 0.489935;     % iVSS_XS

% Falta la matriz de Estequimoetría
Esteq=zeros(NUMREACCIONESBIOL,NUMESTADOSMODASM1);
Esteq(CRECIM_AEROB_XBH,EST_SS) = -1/ParamsEsteq(1);
Esteq(CRECIM_AEROB_XBH,EST_SO) = -(1-ParamsEsteq(1))/ParamsEsteq(1);
Esteq(CRECIM_AEROB_XBH,EST_SNH) = -ParamsEsteq(4);
Esteq(CRECIM_AEROB_XBH,EST_SALK) = -ParamsEsteq(4)/14;
Esteq(CRECIM_AEROB_XBH,EST_XBH) = 1;

Esteq(CRECIM_ANOX_XBH,EST_SS) = -1/ParamsEsteq(1);
Esteq(CRECIM_ANOX_XBH,EST_SNO) = -(1-ParamsEsteq(1))/(2.86*ParamsEsteq(1));
Esteq(CRECIM_ANOX_XBH,EST_SNH) = -ParamsEsteq(4);
Esteq(CRECIM_ANOX_XBH,EST_SALK) = (1-ParamsEsteq(1))/(14*2.86*ParamsEsteq(1)) - ParamsEsteq(4)/14;
Esteq(CRECIM_ANOX_XBH,EST_XBH) = 1;

Esteq(CRECIM_AEROB_XBA,EST_SO) = -(4.57-ParamsEsteq(2))/ParamsEsteq(2);
Esteq(CRECIM_AEROB_XBA,EST_SNO) = 1/ParamsEsteq(2);
Esteq(CRECIM_AEROB_XBA,EST_SNH) = -ParamsEsteq(4)- (1/ParamsEsteq(2));
Esteq(CRECIM_AEROB_XBA,EST_SALK) = -(1/(7*ParamsEsteq(2))) - ParamsEsteq(4)/14;
Esteq(CRECIM_AEROB_XBA,EST_XBA) = 1;

Esteq(LISIS_XBH,EST_XS) = 1 - ParamsEsteq(3);
Esteq(LISIS_XBH,EST_XBH) = -1;
Esteq(LISIS_XBH,EST_XP) = ParamsEsteq(3);
Esteq(LISIS_XBH,EST_XND) = ParamsEsteq(4) - ParamsEsteq(5)*ParamsEsteq(3);

Esteq(LISIS_XBA,EST_XS) = 1 - ParamsEsteq(3);
Esteq(LISIS_XBA,EST_XBA) = -1;
Esteq(LISIS_XBA,EST_XP) = ParamsEsteq(3);
Esteq(LISIS_XBA,EST_XND) = ParamsEsteq(4) - ParamsEsteq(5)*ParamsEsteq(3);

Esteq(AMONIFICACION,EST_SNH) = 1 ;
Esteq(AMONIFICACION,EST_SND) = -1 ;
Esteq(AMONIFICACION,EST_SALK) = 1/14 ;

Esteq(HIDROLISIS_XS,EST_SS) = 1 ;
Esteq(HIDROLISIS_XS,EST_XS) = -1 ;

Esteq(HIDROLISIS_XND,EST_SND) = 1 ;
Esteq(HIDROLISIS_XND,EST_XND) = -1 ;

Esteq(AERACION,EST_SO) = 1 ;


% Coeficientes Cineticos_20
Cineticos20(1) = 6;             % muH 
Cineticos20(2) = 0.80;          % nG
Cineticos20(3) = 0.6;          % bH
Cineticos20(4) = 20;            % kS
Cineticos20(5) = 0.08;          % kA
Cineticos20(6) = 0.05;          % kNHG
Cineticos20(7) = 3;             % kH
Cineticos20(8) = 0.40 ;         % nH
Cineticos20(9) = 0.20 ;        % kOH
Cineticos20(10) = 0.1 ;         % kNO
Cineticos20(11) = 0.03 ;        % kX
Cineticos20(12) = 0.8;          % muA
Cineticos20(13) = 0.13;         % bA
Cineticos20(14) = 0.4;          % kOA
Cineticos20(15) = 1;           % kNH

Arrhenius = ones(1,15);         
Arrhenius(1) = 1.072;           % muH       
Arrhenius(3) = 1.12;            % bH
Arrhenius(5) = 1.072;           % kA
Arrhenius(7) = 1.116;           % kH
Arrhenius(11) = 1.116;          % kX
Arrhenius(12) = 1.103;          % muA
Arrhenius(13) = 1.116;          % bA

