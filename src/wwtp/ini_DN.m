clearvars;

load Input_Data.mat

iniASM1model;

% Influente
Inf_Const(1) = 0;               % t
Inf_Const(2) = 19029;           % Qinf
Inf_Const(3) = 60.653775;       % SS
Inf_Const(4) = 0;               % S0
Inf_Const(5) = 34.6593;         % SI
Inf_Const(6) = 0.;              % SNO
Inf_Const(7) = 36.0;            % SNH
Inf_Const(8) = 1.81961325;      % SND
Inf_Const(9) = 200;             % SALK
Inf_Const(10) = 54.40884;       % XI
Inf_Const(11) = 142.823205;     % XSP
Inf_Const(12) = 29.471455;      % XH
Inf_Const(13) = 0;              % XA
Inf_Const(14) = 0;              % XP
Inf_Const(15) = 8.25994475;     % XND
Inf_Const(16) = 43.35;          % XIN
Inf_Const(17) = 77.983425;      % XSR


% TANQUE_D
% Configuración de Planta
Param_D(1) = 4150.08;         %VASU
Param_D(2) = 0.325;           %DE_TANK
Param_D(3) = 5;               %H_TANK
Param_D(4) = 0.95;            %BETA_FACTOR
Param_D(5) = 3;               %KLa

% Iniciales
x0(1) = 2.82;
x0(2) = 0.02;
x0(3) = 34.66;
x0(4) = 1.76;
x0(5) = 9.35;
x0(6) = 0.52;
x0(7) = 200;
x0(8) = 1176.37;
x0(9) = 54.93;
x0(10) = 1897.83;
x0(11) = 102.63;
x0(12) = 591.89;
x0(13) = 3.03;
x0(14) = 937.27;


% TANQUE_N
% Configuración de Planta
Param_N(1) = 7057.34;                % VASU
Param_N(2) = 0.325;                 % DE_TANK
Param_N(3) = 5;                     % H_TANK

Param_N(4) = 4.6;                   % OTE_A
Param_N(5) = -1.346;                % OTE_B
Param_N(6) = 0.123;                 % OTE_C

Param_N(7) = 0.657;                 % OTE_E
Param_N(8) = -0.018;                % OTE_F
Param_N(9) = 5.52;                  % OTE_K

Param_N(10) = -0.01247;              % OTE_M
Param_N(11) = -0.10843;              % OTE_N
Param_N(12) = 0.037271;              % OTE_P

Param_N(13) = 0.0489;                % Densidad Difusores
Param_N(14) = 0.06;                % Area Difusores

Param_N(15) = 0.66;                 % Alpha
Param_N(16) = 0.95;                 % Beta
Param_N(17) = 1;                    % Theta


% Iniciales
x0(15) = 2.02;
x0(16) = 2;
x0(17) = 34.66;
x0(18) = 9.77;
x0(19) = 1.5;
x0(20) = 0.64;
x0(21) = 200;
x0(22) = 1176.37;
x0(23) = 15.72;
x0(24) = 1904.81;
x0(25) = 104.09;
x0(26) = 596.16;
x0(27) = 1.06;
x0(28) = 937.27;

