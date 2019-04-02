#include "DireLabs.hpp"
#include "dsp/digital.hpp"

struct _brokenclocks : Module {
  enum ParamIds { NUM_PARAMS = 4 };
  enum InputIds { NUM_INPUTS = 1 };
  enum OutputIds { NUM_OUTPUTS = 4 };
  enum LightIds { NUM_LIGHTS = 4 };

  SchmittTrigger clockTrigger;

  _brokenclocks() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {}
  void step() override;
};

void _brokenclocks::step() {
  bool clocked = clockTrigger.process(inputs[0].value);

  for (int i = 0; i < 4; i++) {
    if (clocked) {
      if ((rand() % 100) + 1 < params[i].value) {
        outputs[i].value = 10.0f;
        lights[i].setBrightness(10);
      }
    } else if (!clockTrigger.isHigh()) {
      outputs[i].value = 0.0f;
      lights[i].setBrightness(0);
    }
  }
}

struct _brokenclocksWidget : ModuleWidget {
  _brokenclocksWidget(_brokenclocks *module);
};

_brokenclocksWidget::_brokenclocksWidget(_brokenclocks *module)
    : ModuleWidget(module) {
  setPanel(SVG::load(assetPlugin(plugin, "res/brokenclocks.svg")));

  addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
  addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
  addChild(createWidget<ScrewSilver>(
      Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
  addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH,
                                         RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

  addInput(createInputCentered<PJ301MPort>(
      Vec(box.size.x / 2, box.size.y - 340), module, 0));

  addParam(createParamCentered<RoundSmallBlackKnob>(
      Vec(box.size.x / 2, box.size.y - 300.446), module, 0, 0.0f, 100.0f,
      100.0f));
  addParam(createParamCentered<RoundSmallBlackKnob>(
      Vec(box.size.x / 2, box.size.y - 231.486), module, 1, 0.0f, 100.0f,
      100.0f));
  addParam(createParamCentered<RoundSmallBlackKnob>(
      Vec(box.size.x / 2, box.size.y - 162.647), module, 2, 0.0f, 100.0f,
      100.0f));
  addParam(createParamCentered<RoundSmallBlackKnob>(
      Vec(box.size.x / 2, box.size.y - 93.757), module, 3, 0.0f, 100.0f,
      100.0f));

  addOutput(createOutputCentered<PJ301MPort>(
      Vec(box.size.x / 2, box.size.y - 270.978), module, 0));
  addOutput(createOutputCentered<PJ301MPort>(
      Vec(box.size.x / 2, box.size.y - 202.088), module, 1));
  addOutput(createOutputCentered<PJ301MPort>(
      Vec(box.size.x / 2, box.size.y - 133.202), module, 2));
  addOutput(createOutputCentered<PJ301MPort>(
      Vec(box.size.x / 2, box.size.y - 64.316), module, 3));

  addChild(createLightCentered<TinyLight<GreenLight>>(
      Vec(box.size.x / 2 + 11, box.size.y - 270.978 - 11), module, 0));
  addChild(createLightCentered<TinyLight<GreenLight>>(
      Vec(box.size.x / 2 + 11, box.size.y - 202.088 - 11), module, 1));
  addChild(createLightCentered<TinyLight<GreenLight>>(
      Vec(box.size.x / 2 + 11, box.size.y - 133.202 - 11), module, 2));
  addChild(createLightCentered<TinyLight<GreenLight>>(
      Vec(box.size.x / 2 + 11, box.size.y - 64.316 - 11), module, 3));
}

Model *model_brokenclocks = Model::create<_brokenclocks, _brokenclocksWidget>(
    "DireLabs", "brokenclocks", "Broken Clocks");
