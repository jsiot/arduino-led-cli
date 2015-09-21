var SerialPort = require('serialport').SerialPort;
var serialPort = new SerialPort('/dev/ttyACM0', {
    baudRate: 57600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1
});

var status = process.argv[2];

serialPort.on('open', function(error) {
	serialPort.on('data', function(data) {
	    console.log('data received', data);
	});

	setTimeout(function(){
	    serialPort.write(status);
	}, 3000);
    
	serialPort.on('error', function (err) {
	    console.error("error", err);
	});
});