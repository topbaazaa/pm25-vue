<template>
    <div class="page-container">
        <v-row>
            <v-tabs centered slider-color="yellow" background-color="white" fixed-tabs color="yellow">
                <v-tab>INSIDE</v-tab>
                <v-tab>OUTSIDE</v-tab>
                <v-tab-item v-for="n in 2" :key="n">
                    <v-container fluid id="firstcontain">
                        <v-card class="mx-auto" max-width="100%" color="#FFD600" id="vcardicleft">
                            <br />
                            <v-list-item>
                                <v-list-item-content>
                                    <div v-if="humidity > 60">
                                        <v-icon color="#FFFFFF" size="60px">{{ items[0] }}</v-icon>
                                    </div>
                                    <div v-else>
                                        <v-icon color="#FFFFFF" size="60px">{{ items[1] }}</v-icon>
                                    </div>
                                </v-list-item-content>
                            </v-list-item>
                        </v-card>
                        <v-card class="mx-auto" max-width="95%" color="#FFEB34" id="vcardicmid">
                            <v-list-item three-line>
                                <v-list-item-content>
                                    <div class="overline mb-4">OVERLINE</div>
                                    <v-list-item-title class="headline mb-1">Headline 5</v-list-item-title>
                                    <v-list-item-subtitle>Greyhound divisely hello coldly fonwderfully</v-list-item-subtitle>
                                </v-list-item-content>
                            </v-list-item>
                        </v-card>
                        <v-card class="mx-auto" max-width="95%" color="#FFEB34" id="vcardicright">
                            <v-list-item three-line>
                                <v-list-item-content>
                                    <div class="overline mb-4">OVERLINE</div>
                                    <v-list-item-title class="headline mb-1">Headline 5</v-list-item-title>
                                    <v-list-item-subtitle>Greyhound divisely hello coldly fonwderfully</v-list-item-subtitle>
                                </v-list-item-content>
                            </v-list-item>
                        </v-card>
                        <br />

                        <v-card class="mx-auto" max-width="100%" color="#FFFFFF" id="vcardicleft2">
                            <v-list-item>
                                <v-list-item-content>
                                    <v-row justify="center">
                                        <img class="mr-3" :src="require('../thermometer (1).png')" height="60" />
                                        <v-text class="font" color="#FFFFFF" size="60px">{{ temperature }}</v-text>
                                    </v-row>
                                </v-list-item-content>
                            </v-list-item>
                        </v-card>
                        <v-card class="mx-auto" max-width="95%" color="#FFFFFF" id="vcardicmid2">
                            <v-list-item>
                                <v-list-item-content>
                                    <v-row justify="center">
                                        <img class="mr-3" :src="require('../rain-drops (1).png')" height="60" />
                                        <v-text class="font" color="#FFFFFF" size="60px">{{ humidity }}</v-text>
                                    </v-row>
                                </v-list-item-content>
                            </v-list-item>
                        </v-card>
                        <v-card class="mx-auto" max-width="95%" color="#FFFFFF" id="vcardicright2">
                            <v-list-item>
                                <v-list-item-content>
                                    <v-row justify="center">
                                        <img class="mr-3" :src="require('../sun (1).png')" height="60" />
                                    </v-row>
                                </v-list-item-content>
                            </v-list-item>
                        </v-card>
                        <br />
                        <br />
                        <br />
                        <v-row align="center" justify="center">
                            <v-btn color="success" class="ma-2" @click="overlay = !overlay" height="38px">Show Overlay</v-btn>

                            <v-btn color="success" class="ma-2" @click="overlay = !overlay" height="38px">Show Overlay</v-btn>

                            <v-btn color="success" class="ma-2" @click="overlay = !overlay" height="38px">Show Overlay</v-btn>

                            <v-btn color="success" class="ma-2" @click="overlay = !overlay" height="38px">Show Overlay</v-btn>
                        </v-row>
                        <v-row align="center" justify="center">
                            <v-btn color="success" class="ma-2" @click="overlay = !overlay" height="38px">Show Overlay</v-btn>

                            <v-btn color="success" class="ma-2" @click="overlay = !overlay" height="38px">Show Overlay</v-btn>
                            <v-btn color="success" class="ma-2" @click="overlay = !overlay" height="38px">Show Overlay</v-btn>

                            <v-btn color="success" class="ma-2" @click="overlay = !overlay" height="38px">Show Overlay</v-btn>
                        </v-row>
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
};
firebase.initializeApp(config)
var database = firebase.database()
var contactRef = database.ref('/logDHT')
export default {
  data () {
    return {}
  },
  methods: {},
  mounted () {
    contactRef.limitToLast(1).on('value', (snapshot) => {
      var data = snapshot.val()
      for (var i in data) {
        this.humidity = (data[i].humidity)
        this.temperature = (data[i].temperature)
        if (this.humidity > 60) {
          document.getElementById('vcardicleft').style.backgroundColor = 'red'
        }
        else {document.getElementById('vcardicleft').style.backgroundColor = 'green'}
      }
    })
  },
  data: () => ({
    absolute: true,
    humidity: [],
    temperature: [],
    overlay: false,
    items: ['mdi-weather-hail','home'],

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