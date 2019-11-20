  fs = 8000;     % Sampling frequency in Hz
  nbits = 16;    % number of bits
  acq_ch = 1;   % acquisition channel
  secs2rec= 1;
  % creating object for recording:
  lineinput = audiorecorder(fs, nbits, acq_ch);
 recordblocking(lineinput, secs2rec); % start the recording
  data = getaudiodata(lineinput);

%% Determine the frequency components of the data 
plot(data);
figure(2);
mag = abs(fft(data));
mag = mag(1:end/2);
plot(mag);





