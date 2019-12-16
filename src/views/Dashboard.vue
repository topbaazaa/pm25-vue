<template>
  <div class="page-container">
    <v-card>
      <v-tabs centered slider-color="yellow" background-color="white" fixed-tabs color="deep-purple accent-4">
        <v-tab>INSIDE</v-tab>
        <v-tab>OUTSIDE</v-tab>

        <v-tab-item v-for="n in 3" :key="n">
          <v-container fluid>
            <v-row>
              <v-col v-for="i in 6" :key="i" cols="12" md="4">
                <v-img
                  :src="`https://picsum.photos/500/300?image=${i * n * 5 + 10}`"
                  :lazy-src="`https://picsum.photos/10/6?image=${i * n * 5 + 10}`"
                  aspect-ratio="1"
                ></v-img>
              </v-col>
            </v-row>
          </v-container>
        </v-tab-item>
      </v-tabs>
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
</style>