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
id_user=3425665
id_project=3451857

previous_annotations = conn.get_annotations(id_image = id_image,
                                            id_term = id_term,
                                            id_user = id_user,
                                            id_project= id_project)

print "%d annotations to delete" %len(previous_annotations.data())

#Warning: this will delete all annotations of user id_user in image id_image from project id_project
for annotation in previous_annotations.data():                                                                                  
    conn.delete_annotation(annotation.id)        
