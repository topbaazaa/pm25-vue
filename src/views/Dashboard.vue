<template>
  <div class="page-container">
    <v-row>
      <v-tabs centered slider-color="yellow" background-color="white" fixed-tabs color="yellow">
        <!-- <v-tab>INSIDE</v-tab> -->
        <v-tab background-color="#D2F114">INSIDE</v-tab>
        <v-tab-item v-for="n in 2" :key="n">
          <v-container fluid id="firstcontain">
            <!-- ---------------------------------------left 1----------------------------------------------- -->
            <v-card v-if="dust <= 25"
              class="mx-auto"
              max-width="100%"
              color="#5CD6F1"
              id="vcardicleft"
              justify="center"
            >
            <br />
              <v-list-item>
                <v-list-item-content>
                  <v-row justify="center">
                    <div v-if="dust <= 25">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[0] }}</v-icon>
                    </div>
                    <!-- <div v-else-if="dust > 25 && dust <= 50">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[1] }}</v-icon>
                    </div>
                    <div v-else-if="dust > 50 && dust <= 100">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[2] }}</v-icon>
                    </div>
                    <div v-else-if="dust > 100 && dust <= 200">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[3] }}</v-icon>
                    </div>
                    <div v-else>
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[4] }}</v-icon>
                    </div> -->
                  </v-row>
                </v-list-item-content>
              </v-list-item>
             </v-card>
             <!-- ---------------------------------------left 2----------------------------------------------- -->
             <v-card v-else-if="dust > 25 && dust <= 50"
              class="mx-auto"
              max-width="100%"
              color="#C3DE1D"
              id="vcardicleft"
              justify="center"
            >
            <br />
              <v-list-item>
                <v-list-item-content>
                  <v-row justify="center">
                    <div v-if="dust > 25 && dust <= 50">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[1] }}</v-icon>
                    </div>
                    <!-- <div v-else-if="dust > 25 && dust <= 50">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[1] }}</v-icon>
                    </div>
                    <div v-else-if="dust > 50 && dust <= 100">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[2] }}</v-icon>
                    </div>
                    <div v-else-if="dust > 100 && dust <= 200">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[3] }}</v-icon>
                    </div>
                    <div v-else>
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[4] }}</v-icon>
                    </div> -->
                  </v-row>
                </v-list-item-content>
              </v-list-item>
             </v-card>
             <!-- ---------------------------------------left 3----------------------------------------------- -->
             <v-card v-else-if="dust > 50 && dust <= 100"
              class="mx-auto"
              max-width="100%"
              color="#FFD600"
              id="vcardicleft"
              justify="center"
            >
            <br />
              <v-list-item>
                <v-list-item-content>
                  <v-row justify="center">
                    <div v-if="dust > 50 && dust <= 100">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[2] }}</v-icon>
                    </div>
                    <!-- <div v-else-if="dust > 25 && dust <= 50">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[1] }}</v-icon>
                    </div>
                    <div v-else-if="dust > 50 && dust <= 100">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[2] }}</v-icon>
                    </div>
                    <div v-else-if="dust > 100 && dust <= 200">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[3] }}</v-icon>
                    </div>
                    <div v-else>
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[4] }}</v-icon>
                    </div> -->
                  </v-row>
                </v-list-item-content>
              </v-list-item>
             </v-card>
              <!-- ---------------------------------------left 4----------------------------------------------- -->
             <v-card v-else-if="dust > 100 && dust <= 200"
              class="mx-auto"
              max-width="100%"
              color="#F4A712"
              id="vcardicleft"
              justify="center"
            >
            <br />
              <v-list-item>
                <v-list-item-content>
                  <v-row justify="center">
                    <div v-if="dust > 100 && dust <= 200">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[3] }}</v-icon>
                    </div>
                    <!-- <div v-else-if="dust > 25 && dust <= 50">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[1] }}</v-icon>
                    </div>
                    <div v-else-if="dust > 50 && dust <= 100">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[2] }}</v-icon>
                    </div>
                    <div v-else-if="dust > 100 && dust <= 200">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[3] }}</v-icon>
                    </div>
                    <div v-else>
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[4] }}</v-icon>
                    </div> -->
                  </v-row>
                </v-list-item-content>
              </v-list-item>
             </v-card>
              <!-- ---------------------------------------left 5----------------------------------------------- -->
             <v-card v-else
              class="mx-auto"
              max-width="100%"
              color="#D95454"
              id="vcardicleft"
              justify="center"
            >
            <br />
              <v-list-item>
                <v-list-item-content>
                  <v-row justify="center">
                    <div v-if="dust > 200">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[4] }}</v-icon>
                    </div>
                    <!-- <div v-else-if="dust > 25 && dust <= 50">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[1] }}</v-icon>
                    </div>
                    <div v-else-if="dust > 50 && dust <= 100">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[2] }}</v-icon>
                    </div>
                    <div v-else-if="dust > 100 && dust <= 200">
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[3] }}</v-icon>
                    </div>
                    <div v-else>
                      <v-icon color="#FFFFFF" size="60px" justify="center">{{ items[4] }}</v-icon>
                    </div> -->
                  </v-row>
                </v-list-item-content>
              </v-list-item>
             </v-card>
             <!-- ---------------------------------------mid 1----------------------------------------------- -->
            <v-card v-if="dust <= 25"
              class="mx-auto" 
              max-width="95%" 
              color="#95E2F2"
              id="vcardicmid"
            >
              <v-row justify="center">
                <v-card-title class="headline" >
                  <br />
                  {{dust}} μg/m³
                </v-card-title>
              </v-row>
            </v-card>
            <!-- ---------------------------------------mid 2----------------------------------------------- -->
            <v-card v-else-if="dust > 25 && dust <= 50"
              class="mx-auto" 
              max-width="95%" 
              color="#D2F114"
              id="vcardicmid"
            >
              <v-row justify="center">
                <v-card-title class="headline" >
                  <br />
                  {{dust}} μg/m³
                </v-card-title>
              </v-row>
            </v-card>
            <!-- ---------------------------------------mid 3----------------------------------------------- -->
            <v-card v-else-if="dust > 50 && dust <= 100"
              class="mx-auto" 
              max-width="95%" 
              color="#FFEB34"
              id="vcardicmid"
            >
              <v-row justify="center">
                <v-card-title class="headline" >
                  <br />
                  {{dust}} μg/m³
                </v-card-title>
              </v-row>
            </v-card>
            <!-- ---------------------------------------mid 4----------------------------------------------- -->
            <v-card v-else-if="dust > 100 && dust <= 200"
              class="mx-auto" 
              max-width="95%" 
              color="#F9B636"
              id="vcardicmid"
            >
              <v-row justify="center">
                <v-card-title class="headline" >
                  <br />
                  {{dust}} μg/m³
                </v-card-title>
              </v-row>
            </v-card>
            <!-- ---------------------------------------mid 5----------------------------------------------- -->
             <v-card v-else
              class="mx-auto" 
              max-width="95%" 
              color="#F06B6B"
              id="vcardicmid"
            >
              <v-row justify="center">
                <v-card-title class="headline" >
                  <br />
                  {{dust}} μg/m³
                </v-card-title>
              </v-row>
            </v-card>
             <!-- ---------------------------------------right 1----------------------------------------------- -->
            <v-card v-if="dust <= 25"
            class="mx-auto" 
            max-width="95%" 
            color="#95E2F2" id="vcardicright">
              <v-row justify="center"> 
                <v-card-title class="headline" >
                  <br />
                  Lasttime
                  {{time}}
                </v-card-title>
                </v-row>
            </v-card>
            <!-- ---------------------------------------right 2----------------------------------------------- -->
            <v-card v-else-if="dust > 25 && dust <= 50"
            class="mx-auto" 
            max-width="95%" 
            color="#D2F114" id="vcardicright">
              <v-row justify="center"> 
                <v-card-title class="headline" >
                  <br />
                  Lasttime
                  {{time}}
                </v-card-title>
                </v-row>
            </v-card>
            <!-- ---------------------------------------right 3----------------------------------------------- -->
            <v-card v-else-if="dust > 50 && dust <= 100"
            class="mx-auto" 
            max-width="95%" 
            color="#FFEB34" id="vcardicright">
              <v-row justify="center"> 
                <v-card-title class="headline" >
                  <br />
                  Lasttime
                  {{time}}
                </v-card-title>
                </v-row>
            </v-card>
            <!-- ---------------------------------------right 4----------------------------------------------- -->
            <v-card v-else-if="dust > 100 && dust <= 200"
            class="mx-auto" 
            max-width="95%" 
            color="#F9B636" id="vcardicright">
              <v-row justify="center"> 
                <v-card-title class="headline" >
                  <br />
                  Lasttime
                  {{time}}
                </v-card-title>
                </v-row>
            </v-card>
            <!-- ---------------------------------------right 5----------------------------------------------- -->
            <v-card v-else
            class="mx-auto" 
            max-width="95%" 
            color="#F06B6B" id="vcardicright">
              <v-row justify="center"> 
                <v-card-title class="headline" >
                  <br />
                  Lasttime
                  {{time}}
                </v-card-title>
                </v-row>
            </v-card>
            <br />

            <v-card class="mx-auto" max-width="100%" color="#FFFFFF" id="vcardicleft2">
              <v-list-item>
                <v-list-item-content>
                  <v-row justify="center">
                    <img class="mr-3" :src="require('../thermometer (1).png')" height="60" />
                    <v-text class="font" color="#FFFFFF" size="60px">{{ temperature }} C ํ</v-text>
                  </v-row>
                </v-list-item-content>
              </v-list-item>
            </v-card>
            <v-card class="mx-auto" max-width="95%" color="#FFFFFF" id="vcardicmid2">
              <v-list-item>
                <v-list-item-content>
                  <v-row justify="center">
                    <img class="mr-3" :src="require('../rain-drops (1).png')" height="60" />
                    <v-text class="font" color="#FFFFFF" size="60px">{{ humidity }} %</v-text>
                  </v-row>
                </v-list-item-content>
              </v-list-item>
            </v-card>
            <v-card class="mx-auto" max-width="95%" color="#FFFFFF" id="vcardicright2">
              <v-list-item>
                <v-list-item-content>
                  <v-row justify="center">
                    <img class="mr-3" :src="require('../sun (1).png')" height="60" />
                    <v-text class="font" color="#FFFFFF" size="60px">{{lux}} cd</v-text>
                  </v-row>
                </v-list-item-content>
              </v-list-item>
            </v-card>
            <br />
            <br />
            <br />
          </v-container>
        </v-tab-item>
      </v-tabs>
    </v-row>
    <v-overlay :absolute="absolute" :value="overlay">
      <v-card
        @click="overlay = false"
        color="#FFD600"
        height="40vw"
        width="29vw"
        class="overlayblock"
        id="overlayleft"
      ></v-card>
      <v-card
        @click="overlay = false"
        color="#FFFFFF"
        height="40vw"
        width="32vw"
        class="overlayblock"
        id="overlayright"
      ></v-card>
    </v-overlay>
  </div>
</template>
<script>


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
firebase.initializeApp(config)
var database = firebase.database()
var contactRef = database.ref('/logDHT')
export default {
  
  data() {
    return {}
  },
  methods: {},
  mounted() {
    contactRef.limitToLast(1).on('value', snapshot => {
      var data = snapshot.val()
      for (var i in data) {
        this.humidity = data[i].humidity
        this.temperature = data[i].temperature
        this.lux = data[i].lux
        this.dust = -(data[i].dust)*1000
        this.time = data[i].time
        if (this.dust <= 25) {
          document.getElementById('vcardicleft').style.backgroundColor =
            '#5CD6F1'
          document.getElementById('vcardicmid').style.backgroundColor =
            '#95E2F2'
          document.getElementById('vcardicright').style.backgroundColor =
            '#95E2F2'
        } else if (this.dust > 25 && this.dust <= 50) {
         document.getElementById('vcardicleft').style.backgroundColor =
            '#C3DE1D'
          document.getElementById('vcardicmid').style.backgroundColor =
            '#D2F114'
          document.getElementById('vcardicright').style.backgroundColor =
            '#D2F114'
        } else if (this.dust > 50 && this.dust <= 100) {
          document.getElementById('vcardicleft').style.backgroundColor =
            '#FFD600'
          document.getElementById('vcardicmid').style.backgroundColor =
            '#FFEB34'
          document.getElementById('vcardicright').style.backgroundColor =
            '#FFEB34'
        } else if(this.dust > 100 && this.dust <= 200) {
          document.getElementById('vcardicleft').style.backgroundColor =
            '#F4A712'
          document.getElementById('vcardicmid').style.backgroundColor =
            '#F9B636'
          document.getElementById('vcardicright').style.backgroundColor =
            '#F9B636'
        }
         else {
            document.getElementById('vcardicleft').style.backgroundColor =
            '#D95454'
          document.getElementById('vcardicmid').style.backgroundColor =
            '#F06B6B'
          document.getElementById('vcardicright').style.backgroundColor =
            '#F06B6B'
         }
        
      }
    })
  },
  data: () => ({
    absolute: true,
    humidity: [],
    temperature: [],
    overlay: false,
    items: [
      'mdi-emoticon',
      'mdi-emoticon-happy',
      'mdi-emoticon-neutral',
      'mdi-emoticon-sad',
      'mdi-emoticon-dead'
    ]
  })
}
</script>

<style>
.page-container {
  height: 100%;
  *background-color: rgb(255, 255, 255);
}
.mystyle {
  background-color: '#16a085';
}
.mx-auto {
  display: inline-block;
}
.font {
  font-family: 'Lucida Sans Unicode';
  /*margin:initial;*/
  margin-top: auto;
  margin-bottom: auto;
}
.overlayblock {
  display: block;
  float: left;
}
#overlayleft {
  border-radius: 20px 0 0 20px;
}
#overlayright {
  border-radius: 0 20px 20px 0;
}
#vcardicleft {
  width: 32%;
  height: 130px;
  border-radius: 2vw 0vw 0vw 2vw;
  float: left;
}
#vcardicmid {
  width: 23%;
  height: 130px;
  border-radius: 0 0 0 0;
}
#vcardicright {
  width: 45%;
  height: 130px;
  border-radius: 0vw 2vw 2vw 0vw;
  clear: right;
}
#vcardicleft2 {
  width: 33%;
  height: 80px;
  margin-top: 10px;
  border-radius: 2vw 0vw 0vw 2vw;
  float: left;
}
#vcardicmid2 {
  width: 34%;
  height: 80px;
  margin-top: 10px;
  border-radius: 0 0 0 0;
}
#vcardicright2 {
  width: 33%;
  height: 80px;
  margin-top: 10px;
  border-radius: 0vw 2vw 2vw 0vw;
  clear: right;
}
#firstcontain {
  margin-right: auto;
  margin-left: auto;
  display: block;
  width: 90%;
}
</style>