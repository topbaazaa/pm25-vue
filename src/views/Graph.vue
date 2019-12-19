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
export default {
  components: {
    // Drilldown,
    VueHighcharts
  },
  data() {
    return {
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
                // set up the updating of the chart each second
                var series = this.series[0]
                setInterval(function() {
                  var x = new Date().getTime(), // current time
                    y = Math.random() * 10 + 1
                  series.addPoint([x, y], true, true)
                }, 1000)
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
              name: 'Random data',
              color: '#FFEB34',
              data: (function() {
                // generate an array of random data
                var data = [],
                  time = new Date().getTime(),
                  i
                for (i = -19; i <= 0; i += 1) {
                  data.push({
                    x: time + i * 1000,
                    y: Math.random() * 10 + 1
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
                // set up the updating of the chart each second
                var series = this.series[0]
                setInterval(function() {
                  var x = new Date().getTime(), // current time
                    y = Math.random() * 10 + 1
                  series.addPoint([x, y], true, true)
                }, 1000)
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
              name: 'Random data',
              color: '#FFEB34',
              data: (function() {
                // generate an array of random data
                var data = [],
                  time = new Date().getTime(),
                  i
                for (i = -19; i <= 0; i += 1) {
                  data.push({
                    x: time + i * 1000,
                    y: Math.random() * 10 + 1
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