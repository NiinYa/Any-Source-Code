import discord
import os
import requests
import json
import time

from discord.ext import commands
prefix="`"
bot = commands.Bot(command_prefix=prefix)
client = discord.Client()
my_secret = os.environ['keybot']
file_json = open("embed1.json")

# prsing data JSON
data = json.loads(file_json.read())

# cetak isi data JSON

@client.event
async def on_ready():
  print('Saya sudah login sebagai {0.user}'.format(client))

@client.event
async def on_message(message):
  if message.author==client.user:
    return
  
  if message.content.startswith('`hello'):
    await message.channel.send('Hello!')
  
  if message.content.startswith('`help'):
    await message.channel.send('syntax yang bisa digunakan hanya `hello')

  if message.content.startswith('`laler'):
    await message.channel.send('https://media.discordapp.net/attachments/770262742258810880/840575532336414750/troll_xd.gif')
  if message.content.startswith('`coba'):
    await message.channel.send(data)


  if message.content.startswith('`tes'):
    embedVar = discord.Embed(title="Embed Test", description="This embed chat used to test the code that i code",url="https://i.imgur.com/FtwFqnx.gif", color=0x00FFF9)
    embedVar.set_image(url="https://media.discordapp.net/attachments/804380865844215808/809703160674517072/4784_crumbdance.gif")
    embedVar.add_field(name="Genshin", value="Sampe tipes", inline=False)
    embedVar.add_field(name="Can i PUT URL here?", value="https://htmlcolorcodes.com/color-picker/", inline=False)
    await message.channel.send(embed=embedVar)
  
  if message.content.startswith('`ping'):
    before=time.monotonic()
    ping=(time.monotonic()-before)*100000000
    embedPing = discord.Embed(title="Test Ping",description=f'Your Ping Is ⏳ {int(ping)}ms',color=0x000000)
    await message.channel.send(embed=embedPing)

@bot.command()
async def ping(ctx):
  if ctx.content.startswith('mek'):
    pong=bot.latency
    await ctx.channel.send(pong)
  
  #if message.content.startswith('`mock',):

#f'Your Ping Is ⏳{round(client.latency * 1000)}ms'
#'Pong! {0}'.format(round(client.latency*1000, 1))
client.run(my_secret)
bot.run(my_secret)