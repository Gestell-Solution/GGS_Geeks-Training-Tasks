# DHT11
DHT11 digital sensor with calculate the humidity and temperature sensor it faster than DHT12 but less accurate.</p>
it can calculate until 50 c and 90 in humidity.</p>
we have 4 pin :
vcc </p>
gnd</p>
not used </p>
data</p>
At first it take signal from the micro controller then take low and high signal after that we let it send signal to the micro controller by going high low high,
after this we enter the get data part where we read low then see the pin state if high get data if no shift 1 then read high and repeat.