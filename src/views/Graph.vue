<template>
  <div slot="media">
    <v-tabs
      centered
      slider-color="yellow"
      background-color="white"
      fixed-tabs
      color="yellow"
      id="graphnav"
    >
      <v-tab>DUST</v-tab>
      <v-tab>TEMP</v-tab>
      <v-tab>HUMIDITY</v-tab>
      <v-tab>LUMINANCE</v-tab>
      <!-- --------------------------------- #Grapg 1----------------------------------------------- -->
      <v-tab-item>
        <v-container fluid>
          <v-card hight="100%" width="100%" outlined>
            <vue-highcharts :highcharts="Highcharts" :options="options[0]" ref="drilldownChart"></vue-highcharts>
          </v-card>
        </v-container>
      </v-tab-item>
      <!-- --------------------------------- #Grapg 2----------------------------------------------- -->
      <v-tab-item>
        <v-container fluid>
          <v-card hight="100%" width="100%" outlined>
            <vue-highcharts :highcharts="Highcharts" :options="options[1]" ref="drilldownChart"></vue-highcharts>
          </v-card>
        </v-container>
      </v-tab-item>
      <!-- --------------------------------- #Grapg 3----------------------------------------------- -->
      <v-tab-item>
        <v-container fluid>
          <v-card hight="100%" width="100%" outlined>
            <vue-highcharts :highcharts="Highcharts" :options="options[2]" ref="drilldownChart"></vue-highcharts>
          </v-card>
        </v-container>
      </v-tab-item>
      <!-- --------------------------------- #Grapg 4----------------------------------------------- -->
      <v-tab-item>
        <v-container fluid>
          <v-card hight="100%" width="100%" outlined>
            <vue-highcharts :highcharts="Highcharts" :options="options[3]" ref="drilldownChart"></vue-highcharts>
          </v-card>
        </v-container>
      </v-tab-item>
    </v-tabs>
  </div>
</template>
<script>
import VueHighcharts from 'vue2-highcharts'
import Highcharts from 'highcharts'
import * as firebase from 'firebase'
var config = {
  apiKey: 'AIzaSyCKoH1orPrpHKW9X3273TKUAHeLELmb15E',
  authDomain: 'dust-meter.firebaseapp.com',
  databaseURL: 'https://dust-meter.firebaseio.com',
  projectId: 'dust-meter',
  storageBucket: 'dust-meter.appspot.com',
  messagingSenderId: '2281533914',
  appId: '1:2281533914:web:19c722a94bf6b5a07b90e3',
  measurementId: 'G-PZYC9L456L'
}
if (!firebase.apps.length) {
  firebase.initializeApp(config)
}
var database = firebase.database()
var contactRef = database.ref('/logDHT')

export default {
  components: {
    // Drilldown,
    VueHighcharts
  },
  toDate(dStr,format) {
	var now = new Date();
	if (format == "h:m:s") {
 		now.setHours(dStr.substr(0,dStr.indexOf(":")));
 		now.setMinutes(dStr.substr(dStr.indexOf(":")+1));
 		now.setSeconds(dStr.substr(dStr.indexOf(":")+2));
 		return now;
	}else 
		return "Invalid Format";
},
  //mounted() {},
  data() {
    return {
      data1: [],
      name: ['DUST', 'TEMP', 'HUMIDITY', 'LUMINANCE'],
      Highcharts: Highcharts,
      options: [
        {
          chart: {
            height: '100%',
            type: 'spline',
            animation: Highcharts.svg, // don't animate in old IE
            marginRight: 10,
            events: {
              load: function() {
                contactRef.limitToLast(20).on('value', snapshot => {
                  var data = snapshot.val()
                  console.log(this.series)
                   var series = this.series[0]
                   var b
                  for (var i in data) {
                    //b = toDate(data[i].time,"h:m:s")
                    //alert(b);
                    //console.log(b)
                    //b = new Date(data[i].time);
                    b = data[i].dust *(-1000)
                    series.addPoint([new Date().getTime(),b], true, true)
                    console.log(data[i].dust, data[i].time)
                  }
                })
                // var series = this.series[0]
                // setInterval(function() {
                //   var x = new Date().getTime(), // current time
                //     y = Math.random() * 10 + 1
                 
                // }, 1000)
              }
            }
          },
          time: {
            useUTC: false
          },
          title: {
            text: 'DUST'
          },
          xAxis: {
            type: 'datetime',
            tickPixelInterval: 150
          },
          yAxis: {
            title: {
              text: null
            },
            plotLines: [
              {
                value: 0,
                width: 1,
                color: '#808080'
              }
            ]
          },
          tooltip: {
            headerFormat: '<b>{series.name}</b><br/>',
            pointFormat: '{point.x:%Y-%m-%d %H:%M:%S}<br/>{point.y:.2f}'
          },
          legend: {
            enabled: false
          },
          exporting: {
            enabled: false
          },
          series: [
            {
              name: 'Dust',
              color: '#FFEB34',
              data: (function() {
              /*  contactRef.limitToLast(1).on('value', snapshot => {
                  var data = snapshot.val()
                  console.log(this.series)
                   var series = this.series[0]
                  for (var i in data) {
                    series.addPoint([ new Date().getTime(),data[i].humidity], true, true)
                    console.log(data[i].humidity, data[i].time)
                     }
                })*/
                //generate an array of random data
               var data = [],
                  time = new Date().getTime(),
                  i
                for (i = -20; i <= 0; i += 1) {
                  data.push({
                    x: time + i * 100,
                    
                  })
                }
                // var data = [],
                //   time = new Date().getTime(),
                //   i
                // for (i = -10; i <= 0; i += 1) {
                //   data.push({
                //     x: time + i * 1000,
                //     y: Math.random() * 600 + 1
                //   })
                // }
                return data
              })()
            }
          ]
        },
        {
          chart: {
            height: '100%',
            type: 'spline',
            animation: Highcharts.svg, // don't animate in old IE
            marginRight: 10,
            events: {
              load: function() {
                contactRef.limitToLast(20).on('value', snapshot => {
                  var data = snapshot.val()
                  console.log(this.series)
                   var series = this.series[0]
                  for (var i in data) {
                    series.addPoint([new Date().getTime(),data[i].temperature], true, true)
                    console.log(data[i].temperature, data[i].time)
                  }
                })
                // var series = this.series[0]
                // setInterval(function() {
                //   var x = new Date().getTime(), // current time
                //     y = Math.random() * 10 + 1
                 
                // }, 1000)
              
              }
            }
          },
          time: {
            useUTC: false
          },
          title: {
            text: 'TEMP'
          },
          xAxis: {
            type: 'datetime',
            tickPixelInterval: 150
          },
          yAxis: {
            title: {
              text: null
            },
            plotLines: [
              {
                value: 0,
                width: 1,
                color: '#808080'
              }
            ]
          },
          tooltip: {
            headerFormat: '<b>{series.name}</b><br/>',
            pointFormat: '{point.x:%Y-%m-%d %H:%M:%S}<br/>{point.y:.2f}'
          },
          legend: {
            enabled: false
          },
          exporting: {
            enabled: false
          },
          series: [
            {
              name: 'Temp',
              color: '#FFEB34',
              data: (function() {
                // generate an array of random data
                var data = [],
                  time = new Date().getTime(),
                  i
                for (i = -19; i <= 0; i += 1) {
                  data.push({
                    x: time + i * 100,
                    
                  })
                }
                return data
              })()
            }
          ]
        },
        {
          chart: {
            height: '100%',
            type: 'spline',
            animation: Highcharts.svg, // don't animate in old IE
            marginRight: 10,
            events: {
              load: function() {
                contactRef.limitToLast(20).on('value', snapshot => {
                  var data = snapshot.val()
                  console.log(this.series)
                   var series = this.series[0]
                  for (var i in data) {
                    series.addPoint([new Date().getTime(),data[i].humidity], true, true)
                    console.log(data[i].temperature, data[i].time)
                  }
                })
                // var series = this.series[0]
                // setInterval(function() {
                //   var x = new Date().getTime(), // current time
                //     y = Math.random() * 10 + 1
                 
                // }, 1000)
              }
            }
          },
          time: {
            useUTC: false
          },
          title: {
            text: 'HUMIDITY'
          },
          xAxis: {
            type: 'datetime',
            tickPixelInterval: 150
          },
          yAxis: {
            title: {
              text: null
            },
            plotLines: [
              {
                value: 0,
                width: 1,
                color: '#808080'
              }
            ]
          },
          tooltip: {
            headerFormat: '<b>{series.name}</b><br/>',
            pointFormat: '{point.x:%Y-%m-%d %H:%M:%S}<br/>{point.y:.2f}'
          },
          legend: {
            enabled: false
          },
          exporting: {
            enabled: false
          },
          series: [
            {
              name: 'HUMIDITY',
              color: '#FFEB34',
              data: (function() {
                // generate an array of random data
                var data = [],
                  time = new Date().getTime(),
                  i
                for (i = -19; i <= 0; i += 1) {
                  data.push({
                    x: time + i * 100,
                    
                  })
                }
                return data
              })()
            }
          ]
        },
        {
          chart: {
            height: '100%',
            type: 'spline',
            animation: Highcharts.svg, // don't animate in old IE
            marginRight: 10,
            events: {
              load: function() {
                contactRef.limitToLast(20).on('value', snapshot => {
                  var data = snapshot.val()
                  console.log(this.series)
                   var series = this.series[0]
                  for (var i in data) {
                    series.addPoint([new Date().getTime(),data[i].lux], true, true)
                    console.log(data[i].lux, data[i].time)
                  }
                })
              }
            }
          },
          time: {
            useUTC: false
          },
          title: {
            text: 'LUMINANCE'
          },
          xAxis: {
            type: 'datetime',
            tickPixelInterval: 150
          },
          yAxis: {
            title: {
              text: null
            },
            plotLines: [
              {
                value: 0,
                width: 1,
                color: '#808080'
              }
            ]
          },
          tooltip: {
            headerFormat: '<b>{series.name}</b><br/>',
            pointFormat: '{point.x:%Y-%m-%d %H:%M:%S}<br/>{point.y:.2f}'
          },
          legend: {
            enabled: false
          },
          exporting: {
            enabled: false
          },
          series: [
            {
              name: 'LUMINANCE',
              color: '#FFEB34',
              data: (function() {
                // generate an array of random data
                var data = [],
                  time = new Date().getTime(),
                  i
                for (i = -19; i <= 0; i += 1) {
                  data.push({
                    x: time + i * 100,
                    
                  })
                }
                return data
              })()
            }
          ]
        }
      ]
    }
  }
}
</script>
<style>
.v-slide-group {
}
</style>