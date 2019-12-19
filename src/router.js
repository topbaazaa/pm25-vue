import Vue from 'vue'
import Router from 'vue-router'
import Dashbardlayout from './layouts/DashboardLayout.vue'

import Dashboard from './views/Dashboard'
import Graph from './views/Graph'
import Prevent from './views/Prevent'
Vue.use(Router)

export default new Router({
  mode: 'history',
  base: process.env.BASE_URL,
  linkActiveClass: 'active',
  routes: [
    {
      path: '/',
      component: Dashbardlayout,
      children: [
        {
          path: '/dashboard',
          alias: '/',
          name: 'dashboard',
          component: Dashboard
        },
        {
          path: '/graph',
          name: 'graph',
          component: Graph
        },
        {
          path: '/prevent',
          name: 'prevent',
          component: Prevent
        }
      ]
    }
  ]
})
