# -*- coding: utf-8 -*-

#
# * Copyright (c) 2009-2015. Authors: see NOTICE file.
# *
# * Licensed under the Apache License, Version 2.0 (the "License");
# * you may not use this file except in compliance with the License.
# * You may obtain a copy of the License at
# *
# *      http://www.apache.org/licenses/LICENSE-2.0
# *
# * Unless required by applicable law or agreed to in writing, software
# * distributed under the License is distributed on an "AS IS" BASIS,
# * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# * See the License for the specific language governing permissions and
# * limitations under the License.
# */


__author__          = "Marée Raphaël <raphael.maree@ulg.ac.be>"
__copyright__       = "Copyright 2010-2015 University of Liège, Belgium, http://www.cytomine.be/"


from cytomine import Cytomine
from cytomine.models import *
from shapely.geometry.polygon import Polygon
from shapely.geometry import Polygon,Point,box
import sys


#Cytomine connection parameters
cytomine_host="cytomine.icube.unistra.fr"
cytomine_public_key="fd0120c4-d917-4eb6-81f8-149312ccf8c9"
cytomine_private_key="61f7109d-2285-4c0b-87de-da212859257b"


#Connection to Cytomine Core
conn = Cytomine(cytomine_host, cytomine_public_key, cytomine_private_key, base_path = '/api/', working_path = '/tmp/', verbose= True)


#Replace XXX by your values
#id_image=3452832
id_image=int(sys.argv[1])
id_term=3478753
##id_term = int (sys.argv[1])

x1 = int(sys.argv[2])
y1 = int(sys.argv[3])
x2 = int(sys.argv[4])
y2 = int(sys.argv[5])
x3 = int(sys.argv[6])
y3 = int(sys.argv[7])
x4 = int(sys.argv[8])
y4 = int(sys.argv[9])



#Create one geometrical object locally (using shapely)
#circle = Point(100,100).buffer(1000)
#annotation.location=circle.wkt
#rectangle = box(37399.06218758971, 60113.05496935718, 45831.445059508864, 63326.69700003889, ccw=True)
#rectangle = box(3040, 3040, 0, 0, ccw=True)
#rectangle = box(int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]), int(sys.argv[4]), ccw=True)
polygon = Polygon([[x1,y1], [x2,y2], [x3,y3], [x4,y4]])
#polygon = Polygon([[0,0], [1520,1520], [1520,0]])
annotation.location = polygon.wkt
#rectangle = box(x1, y1, x2, y2, ccw=True)
#annotation.location=rectangle.wkt
#point = Point(1000,1000)  #point at position (1000,1000) where (0,0) is bottom left corner
#annotation.location=point.wkt

#Add annotation to cytomine server
new_annotation = conn.add_annotation(annotation.location, id_image)
#Add term from the project's ontology
conn.add_user_annotation_term(new_annotation.id, term=id_term)
#Add property,value to the annotation
annotation_property = conn.add_annotation_property(new_annotation.id, "my_property", 10)
