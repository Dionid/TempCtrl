// load("api_net.js");

// Net.serve({
//     addr: 'tcp://80',
//     onconnect: function(conn) {
//         print('Connected from:', Net.ctos(conn, false, true, true));
//     },
//     ondata: function(conn, data){
//         print('Received data from:', Net.ctos(conn, false, true, true), ':', data);
//         Net.send(conn, data);            // Echo received data back
//         Net.discard(conn, data.length);  // Discard received data
//     },
//     onclose: function(conn){
//         print("Disconnected!");
//     },
// });
//
//
// RPC.addHandler('ServerTest', function(args) {
//   return { success: "Works" };
// }, null);
