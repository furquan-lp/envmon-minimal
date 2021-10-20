load('api_config.js');
load('api_rpc.js');
load('api_dht.js');
load('api_mq135.js');
load('api_timer.js');

print('-Environment monitor begin-');
print('Preliminary build');

let pinDHT = Cfg.get('app.dhtpin');
let pinMQ = Cfg.get('app.mq135pin');
let dht = DHT.create(pinDHT, DHT.DHT22);

MQ135.attach(pinMQ);

Timer.set(1000, true, function() {
  print('Temperature:', dht.getTemp(), ' Humidity:', dht.getHumidity(), '%');
  print('Air Quality Coefficient:', MQ135.getPPM(pinMQ));
}, null);

/*RPC.addHandler('Temp.Read', function(args) {
  return { value: dht.getTemp() };
});*/
