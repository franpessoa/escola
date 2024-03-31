let mapa = L.map("map")
var toner = new L.tileLayer('https://{s}.basemaps.cartocdn.com/light_all/{z}/{x}/{y}.png', {
    attribution: '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>, &copy; <a href="https://carto.com/attributions">CARTO</a>'
});

mapa.addLayer(toner)

let casa = L.marker([-23.56970, -46.72806]).addTo(mapa);
casa.bindPopup("Meu quarto")

let ponto = L.marker([-23.56861, -46.73169]).addTo(mapa);
ponto.bindPopup("Ponto de ônibus do ICB")

let chacara = L.marker([-21.59490, -46.91307]).addTo(mapa);
chacara.bindPopup("Chácara do meu bisavô")

let arco = L.marker([-23.56977, -46.72569]).addTo(mapa);
arco.bindPopup("Arco Cooperativa, minha escola no sexto e sétimo ano")

let movimento = L.marker([-23.57024, -46.72535]).addTo(mapa);
movimento.bindPopup("Movimento, a minha escola de música")

let itaca = L.marker([-23.59666, -46.74639]).addTo(mapa);
itaca.bindPopup("O Ítaca, minha escola atual");

let latlng_pl = [
    [-23.6016, -46.7481],
    [-23.5602, -46.7439],
    [-23.5495, -46.7320],
    [-23.5591, -46.7130],
    [-23.5631, -46.7061],
    [-23.56738, -46.70197],
    [-23.5532, -46.6740],
    [-23.5556, -46.6625],
    [-23.5761, -46.6998]
]
var circle = L.polygon(latlng_pl, {
    color: 'purple',
    fillOpacity: 0.25,
}).addTo(mapa);

L.Routing.control({
    waypoints: [
      L.latLng(-23.56970, -46.72806),
      L.latLng(-23.59666, -46.74639)
    ],
    lineOptions: {
        addWaypoints: false,
        styles: [{color: "red"}]
    },
    fitSelectedRoutes: false,
    createMarker: function() { return null; }
}).addTo(mapa).hide();

L.Routing.control({
    waypoints: [
      L.latLng(-23.59666, -46.74639),
      L.latLng(-23.57131, -46.70917),
      L.latLng(-23.56861, -46.73169),
    ],
    lineOptions: {
        addWaypoints: false,
        styles: [{color: "green"}]
    },
    fitSelectedRoutes: false,
    createMarker: function() { return null; }
}).addTo(mapa).hide();

mapa.setView([-22.56, -46.582], 9);