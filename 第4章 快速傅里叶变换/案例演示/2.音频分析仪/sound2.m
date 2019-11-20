
%% Step 1: Create an analog input object to communicate with data acquisition device
% In this case, a Windows sound card is used ('winsound').
ai = analoginput('winsound');
addchannel(ai,1);

%% Step 2: Configure the analog input to acquire 1 seconds of data at 8kHz
fs = 8000;
duration = 1;
set (ai, 'SampleRate', fs);
set (ai, 'SamplesPerTrigger', duration*fs);

%% Step 3: Start the acquisition and retrieve the data
start(ai);
data = getdata(ai);


%% Step 4: Determine the frequency components of the data
xfft = abs(fft(data));
mag = 20*log10(xfft);
mag = mag(1:end/2);
plot(mag);

%% Step 5: Clean up
delete(ai);
clear ai




