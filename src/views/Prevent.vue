<template>
  <div class="page-container">
    <v-card color="#FFC21C" outlined>
      <br />
      <v-row justify="center">
        <img class="mr-3" :src="require('../name1.jpg')" height="45vm" id="mre" />
      </v-row>
      <v-row justify="center">
        <img class="mr-3" :src="require('../1.jpg')" height="95%" />
        <img class="mr-3" :src="require('../2.jpg')" height="95%" />
        <img class="mr-3" :src="require('../3.jpg')" height="95%" />
        <img class="mr-3" :src="require('../4.jpg')" height="95%" />
        <img class="mr-3" :src="require('../5.jpg')" height="95%" />
      </v-row>
      <br />
    </v-card>

    <v-card class="mx-auto" outlined>
      <br />
      <v-row justify="center">
        <img class="mr-3" :src="require('../หฟ.jpg')" height="40vm" />
      </v-row>
      <v-row justify="center">
        <img class="mr-3" :src="require('../6.jpg')" height="80%" />
        <img class="mr-3" :src="require('../7.jpg')" height="80%" />
        <img class="mr-3" :src="require('../8.jpg')" height="95%" />
        <img class="mr-3" :src="require('../9.jpg')" height="95%" />
        <img class="mr-3" :src="require('../10.jpg')" height="95%" />
        <img class="mr-3" :src="require('../11.jpg')" height="95%" />
      </v-row>
    </v-card>
  </div>
</template>
<script>
export default {
  data() {
    return {}
  },
  methods: {}
}
</script>

<style>
.page-container {
  height: 100%;
}
.mr-3 #mre {
  clear: both;
}
</style>