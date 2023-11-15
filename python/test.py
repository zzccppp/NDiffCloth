from ndf import *

test_json_string = """
{
    "attachmentPoints": "CUSTOM_ARRAY",
    "backwardConvergenceThresh": 0.0005,
    "camFocusPointType": "CLOTH_CENTER",
    "camFocusPos": [
        0.0,
        0.0,
        0.0
    ],
    "camPos": [
        -22.14,
        9.24,
        7.59
    ],
    "customAttachmentVertexIdx": [
        [
            0.0,
            [
                394,
                32
            ]
        ]
    ],
    "fabric": {
        "clothDimX": 6.0,
        "clothDimY": 6.0,
        "color": [
            1.0,
            0.0,
            0.0
        ],
        "custominitPos": false,
        "density": 0.224,
        "fabricIdx": 6,
        "gridNumX": 40,
        "gridNumY": 80,
        "initPosFile": "",
        "isModel": true,
        "k_stiff_bending": 120.0,
        "k_stiff_stretching": 1200.0,
        "keepOriginalScalePoint": false,
        "name": "remeshed/agenthat2-579-rotated.obj"
    },
    "forwardConvergenceThresh": 1e-08,
    "name": "demo_wearhat",
    "orientation": "FRONT",
    "primitiveConfig": "PLANE_BUST_WEARHAT",
    "sceneBbox": {
        "max": [
            7.0,
            10.0,
            5.0
        ],
        "min": [
            -5.0,
            -1.5,
            -14.0
        ]
    },
    "sockLegOrientation": [
        0.0,
        0.0,
        0.0
    ],
    "stepNum": 400,
    "timeStep": 0.01,
    "trajectory": "CORNERS_2_WEARHAT",
    "upVector": [
        0.0,
        0.0,
        0.0
    ],
    "windConfig": "NO_WIND"
}
"""

if __name__ == '__main__':
    scene = SceneConfiguration.load_json_string(test_json_string)
    
    print(scene.dump_json_string())