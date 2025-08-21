waxClass{"AppDelegate", protocols = {"UIApplicationDelegate"}}

function applicationDidFinishLaunching(self, application)
  local frame = UIScreen:mainScreen():bounds()
  self.window = UIWindow:initWithFrame(frame)
  self.window:setBackgroundColor(UIColor:orangeColor())

  -- Required as window root since iOS 13
  local rootVC = UIViewController:init()

  local view = UIView:initWithFrame(frame)
  local button = UIButton:buttonWithType(UIButtonTypeRoundedRect)
  button:setTitle_forState("Test GC", UIControlStateNormal)
  button:setFrame(CGRect(0, 0, 120, 100))
  button:addTarget_action_forControlEvents(self, "gcTouched:", UIControlEventTouchUpInside)
  view:addSubview(button)

  local rvcView = rootVC:view()
  rvcView:addSubview(view)

  self.window:setRootViewController(rootVC)
  self.window:makeKeyAndVisible()
  return true
end

function gcTouched(self, sender)
  puts("boom")
  collectgarbage("collect")
end
