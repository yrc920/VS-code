# -*- coding: utf-8 -*-
"""
Created on Tue Aug 20 22:51:07 2019

@author: hynev
"""

from pyecharts.charts import Bar
from pyecharts import options as opts
from faker import Faker

c = (
  Bar(
    init_opts=opts.InitOpts(
      width="800px",
      height="800px"
    )
  )
    .add_xaxis(Faker.choose())
    .add_yaxis("商家A", Faker.values())
    .add_yaxis("商家B", Faker.values())
    .set_global_opts(
    title_opts=opts.TitleOpts(
      title="Bar-背景图基本示例",
      subtitle="我是副标题",
      title_textstyle_opts=opts.TextStyleOpts(color="white"),
    )
  )
)
c.render()