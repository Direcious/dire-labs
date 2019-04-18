#include "DireLabs.hpp"

struct _188vert : Module {
  enum ParamIds { NUM_PARAMS = 8 };
  enum InputIds { NUM_INPUTS = 1 };
  enum OutputIds { NUM_OUTPUTS = 16 };
  enum LightIds { NUM_LIGHTS = 32 };

  _188vert() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {}
  void step() override;
};

void _188vert::step() {
  float lastIn = 0.0f;
  lastIn = inputs[0].normalize(lastIn);
  float out = 0.0f;
  for (int i = 0; i < 16; i++) {
    if ((i % 2) == 0.0f) {
      out = -(lastIn * params[(i) / 2].value);
    } else {
      out = lastIn * params[(i - 1) / 2].value;
    }
    outputs[i].value = out;
    lights[2 * i].setBrightnessSmooth(fmaxf(0.0f, out / 5.0f));
    lights[2 * i + 1].setBrightnessSmooth(fmaxf(0.0f, -out / 5.0f));
  }
}

struct _188vertWidget : ModuleWidget {
  _188vertWidget(_188vert *module);
};

_188vertWidget::_188vertWidget(_188vert *module) : ModuleWidget(module) {
  setPanel(SVG::load(assetPlugin(plugin, "res/188vert.svg")));

  addChild(createWidget<ScrewSilver>(Vec(15, 0)));
  addChild(createWidget<ScrewSilver>(Vec(box.size.x - 30, 0)));
  addChild(createWidget<ScrewSilver>(Vec(15, box.size.y - 15)));
  addChild(createWidget<ScrewSilver>(Vec(box.size.x - 30, box.size.y - 15)));

  addInput(createInputCentered<PJ301MPort>(
      Vec(box.size.x / 2, box.size.y - 348), module, 0));

  addParam(createParam<RoundBlackKnob>(Vec(45.308, 47.753), module, 0, 0.0f,
                                       1.0f, 0.0f));
  addParam(createParam<RoundBlackKnob>(Vec(45.308, 86.198), module, 1, 0.0f,
                                       1.0f, 0.0f));
  addParam(createParam<RoundBlackKnob>(Vec(45.308, 124.639), module, 2, 0.0f,
                                       1.0f, 0.0f));
  addParam(createParam<RoundBlackKnob>(Vec(45.308, 163.084), module, 3, 0.0f,
                                       1.0f, 0.0f));
  addParam(createParam<RoundBlackKnob>(Vec(45.308, 201.529), module, 4, 0.0f,
                                       1.0f, 0.0f));
  addParam(createParam<RoundBlackKnob>(Vec(45.308, 239.974), module, 5, 0.0f,
                                       1.0f, 0.0f));
  addParam(createParam<RoundBlackKnob>(Vec(45.308, 278.415), module, 6, 0.0f,
                                       1.0f, 0.0f));
  addParam(createParam<RoundBlackKnob>(Vec(45.308, 316.86), module, 7, 0.0f,
                                       1.0f, 0.0f));

  addOutput(createOutput<PJ301MPort>(Vec(9.507, 50.397), module, 0));
  addOutput(createOutput<PJ301MPort>(Vec(86.393, 50.397), module, 1));
  addOutput(createOutput<PJ301MPort>(Vec(9.507, 88.842), module, 2));
  addOutput(createOutput<PJ301MPort>(Vec(86.393, 88.842), module, 3));
  addOutput(createOutput<PJ301MPort>(Vec(9.507, 127.283), module, 4));
  addOutput(createOutput<PJ301MPort>(Vec(86.393, 127.283), module, 5));
  addOutput(createOutput<PJ301MPort>(Vec(9.507, 165.728), module, 6));
  addOutput(createOutput<PJ301MPort>(Vec(86.393, 165.728), module, 7));
  addOutput(createOutput<PJ301MPort>(Vec(9.507, 204.173), module, 8));
  addOutput(createOutput<PJ301MPort>(Vec(86.393, 204.173), module, 9));
  addOutput(createOutput<PJ301MPort>(Vec(9.507, 242.614), module, 10));
  addOutput(createOutput<PJ301MPort>(Vec(86.393, 242.614), module, 11));
  addOutput(createOutput<PJ301MPort>(Vec(9.507, 281.059), module, 12));
  addOutput(createOutput<PJ301MPort>(Vec(86.393, 281.059), module, 13));
  addOutput(createOutput<PJ301MPort>(Vec(9.507, 319.504), module, 14));
  addOutput(createOutput<PJ301MPort>(Vec(86.393, 319.504), module, 15));

  addChild(createLightCentered<TinyLight<GreenRedLight>>(Vec(30.814, 50.414),
                                                         module, 0));
  addChild(createLightCentered<TinyLight<GreenRedLight>>(Vec(107.702, 50.414),
                                                         module, 2));
  addChild(createLightCentered<TinyLight<GreenRedLight>>(Vec(30.814, 88.859),
                                                         module, 4));
  addChild(createLightCentered<TinyLight<GreenRedLight>>(Vec(107.702, 88.859),
                                                         module, 6));
  addChild(createLightCentered<TinyLight<GreenRedLight>>(Vec(30.814, 127.304),
                                                         module, 8));
  addChild(createLightCentered<TinyLight<GreenRedLight>>(Vec(107.702, 127.304),
                                                         module, 10));
  addChild(createLightCentered<TinyLight<GreenRedLight>>(Vec(30.814, 165.745),
                                                         module, 12));
  addChild(createLightCentered<TinyLight<GreenRedLight>>(Vec(107.702, 165.745),
                                                         module, 14));
  addChild(createLightCentered<TinyLight<GreenRedLight>>(Vec(30.814, 204.19),
                                                         module, 16));
  addChild(createLightCentered<TinyLight<GreenRedLight>>(Vec(107.702, 204.19),
                                                         module, 18));
  addChild(createLightCentered<TinyLight<GreenRedLight>>(Vec(30.814, 242.635),
                                                         module, 20));
  addChild(createLightCentered<TinyLight<GreenRedLight>>(Vec(107.702, 242.635),
                                                         module, 22));
  addChild(createLightCentered<TinyLight<GreenRedLight>>(Vec(30.814, 281.076),
                                                         module, 24));
  addChild(createLightCentered<TinyLight<GreenRedLight>>(Vec(107.702, 281.076),
                                                         module, 26));
  addChild(createLightCentered<TinyLight<GreenRedLight>>(Vec(30.814, 319.521),
                                                         module, 28));
  addChild(createLightCentered<TinyLight<GreenRedLight>>(Vec(107.702, 319.521),
                                                         module, 30));
}

Model *model_188vert =
    Model::create<_188vert, _188vertWidget>("DireLabs", "188vert", "188vert");
