<template>
  <v-app id="inspire" style="height: 100vh;">
    <v-card flat color="#f0f0f7" style="height:100%">
      <v-toolbar color="#FFEB34" dark flat>
        <v-app-bar-nav-icon @click.stop="drawer = !drawer"></v-app-bar-nav-icon>
        <v-spacer></v-spacer>
      </v-toolbar>
      <v-navigation-drawer v-model="drawer" absolute temporary>
        <v-list-item>
          <v-list-item-content>
            <v-list-item-title class="title">PM 2.5</v-list-item-title>
            <v-list-item-subtitle>Dashboard</v-list-item-subtitle>
          </v-list-item-content>
        </v-list-item>

        <v-divider></v-divider>

        <v-list dense nav>
          <v-list-item v-for="item in items" :key="item.title" link @click="linkTo(item.link)">
            <v-list-item-icon>
              <v-icon>{{ item.icon }}</v-icon>
            </v-list-item-icon>

            <v-list-item-content>
              <v-list-item-title>{{ item.title }}</v-list-item-title>
            </v-list-item-content>
          </v-list-item>
        </v-list>
      </v-navigation-drawer>
      <div class="main-body">
        <transition name="page" mode="out-in">
          <router-view></router-view>
        </transition>
      </div>
    </v-card>
  </v-app>
</template>

<script>
export default {
  data() {
    return {
      activeLink: '/',
      drawer: null,
      items: [
        { title: 'Air Quality', icon: 'mdi-view-dashboard' , link:'/'},
        { title: 'Graph', icon: 'mdi-image', link:'/graph' },
        { title: 'Prevent', icon: 'mdi-help-box' , link:'/prevent'}
      ],
      right: null
    }
  },
  mounted: function() {
    this.activeLink = this.$route.path
  },
  methods: {
    linkTo(path) {
      console.log(this.activeLink)
      if (path != this.$route.path) {
        this.$router.push(path)
        this.activeLink = this.$route.path
      }
    }
  },
  watch: {
    $route(to) {
      this.activeLink = to.path
    }
  }
}
</script>

<style>
.page-enter-active,
.page-leave-active {
  transition: all 0.15s ease;
}
.page-enter {
  transform: translateX(20px);
  opacity: 0;
}

.page-leave-to {
  transform: translateX(-20px);
  opacity: 0;
}

.main-body {
  padding: 20px;
  background-color: #f0f0f7;
}

.card--flex-toolbar {
  margin-top: -64px;
}
</style>
